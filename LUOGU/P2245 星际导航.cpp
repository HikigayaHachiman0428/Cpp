#include <iostream>
#include <algorithm>
using namespace std;

// 二进制倍增，每次跳2^i步，复杂度O(nlogn)，查询复杂度O(log(n))
const int N = 1e5 + 1;

struct Edge
{
    int to;
    int nxt;
    int w;
} e[3 * N]; //链式前项星

int n, m;
int depth[N]; //节点深度
int Log[N];
int f[N][25], w[N][25]; //倍增数组, 代表从i号节点往上跳2^i层
int head[N], tot;

void addEdge(int x, int y, int w)
{
    e[++tot].to = y;
    e[tot].w = w;
    e[tot].nxt = head[x];
    head[x] = tot;
}

struct edge
{
    int x, y, w;
} a[3 * N];

int fa[N];
int cnt;

bool cmp(edge x, edge y)
{
    return x.w < y.w;
}

void init()
{
    for (int i = 0; i <= n; i++)
        fa[i] = i;
}

int find(int x)
{
    if (x == fa[x])
        return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int x, int y, int w)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        fa[fy] = fx;
        addEdge(x, y, w);
        addEdge(y, x, w);
        cnt++;
    }
}

void krustal()
{
    sort(a + 1, a + 1 + m, cmp);
    init();
    for (int i = 1; i <= m; ++i)
    {
        merge(a[i].x, a[i].y, a[i].w);
        if (cnt == n - 1)
            break;
    }
}
bool vis[N];
void dfs(int cur)
{
    vis[cur] = true;
    for (int i = head[cur]; i > 0; i = e[i].nxt)
    {
        if (!vis[e[i].to])
        {
            depth[e[i].to] = depth[cur] + 1;
            f[e[i].to][0] = cur;
            w[e[i].to][0] = e[i].w;
            dfs(e[i].to);
        }
    }
}

void initLCA()
{
    for (int i = 1; i < 25; ++i)
    {
        for (int node = 1; node <= n; ++node)
        {
            f[node][i] = f[f[node][i - 1]][i - 1];
            w[node][i] = max(w[node][i - 1], w[f[node][i - 1]][i - 1]);
        }
    }
}

void lca(int x, int y)
{
    if (find(x) != find(y))
    {
        cout << "impossible\n";
        return;
    }
    // 把两个点升至同一高度，再一起跳
    if (depth[x] < depth[y])
    {
        swap(x, y);
    }
    int ans = -1e9;
    while (depth[x] > depth[y])
    {
        ans = max(ans, w[x][Log[depth[x] - depth[y]]]);
        x = f[x][Log[depth[x] - depth[y]]];
    }
    if (x == y)
    {
        cout << ans << "\n";
        return;
    }
    // 两个点同时往上跳，跳到LCA的下一层为止
    for (int i = Log[depth[x]]; i >= 0; --i)
    {
        if (f[x][i] != f[y][i])
        {
            ans = max(ans, w[x][i]);
            ans = max(ans, w[y][i]);
            x = f[x][i];
            y = f[y][i];
        }
    }
    ans = max(ans, w[x][0]);
    ans = max(ans, w[y][0]);
    cout << ans << "\n";
}

/*
倍增算法时间复杂度是O(nlogn)
*/
int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y, w;
        cin >> x >> y >> w;
        a[i] = {x, y, w};
    }
    krustal();
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
            dfs(i); // 建树
    }
    // 预处理，常数优化
    for (int i = 2; i <= n; ++i)
    {
        Log[i] = Log[i >> 1] + 1;
    }
    initLCA();
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        lca(x, y);
    }
    return 0;
}
