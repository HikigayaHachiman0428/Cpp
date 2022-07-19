#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// 二进制倍增，每次跳2^i步，复杂度O(nlogn)，查询复杂度O(log(n))
const int N = 500001;

struct Edge
{
    int x;
    int y;
    int w;
} e[2 * N]; //链式前项星

bool cmp(Edge a, Edge b)
{
    return a.w > b.w;
}

int n, m;
int depth[N]; //节点深度
int Log[N];
int f[N][25], w[N][25]; //倍增数组, 代表从i号节点往上跳2^i层
int head[N], tot;

struct path
{
    int to;
    int nxt;
    int w;
} g[2 * N];

void addpath(int x, int y, int w)
{
    g[++tot].to = y;
    g[tot].w = w;
    g[tot].nxt = head[x];
    head[x] = tot;
}

int fa[N];

int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

void krustal()
{
    for (int i = 0; i <= n; ++i)
        fa[i] = i;
    sort(e + 1, e + 1 + m, cmp);
    int cnt = 0;
    for (int i = 1; i <= m; ++i)
    {
        int fx = find(e[i].x);
        int fy = find(e[i].y);
        if (fx != fy)
        {
            fa[fx] = fy;
            addpath(e[i].x, e[i].y, e[i].w);
            addpath(e[i].y, e[i].x, e[i].w);
            cnt++;
        }
        if (cnt == n - 1)
            break;
    }
}

bool vis[N];
void dfs(int cur)
{
    vis[cur] = true;
    for (int i = head[cur]; i > 0; i = g[i].nxt) // 链式前项星遍历
    {
        if (!vis[g[i].to])
        {
            depth[g[i].to] = depth[cur] + 1;
            f[g[i].to][0] = cur;
            w[g[i].to][0] = g[i].w;
            dfs(g[i].to);
        }
    }
}

void initLCA()
{
    // 处理f数组
    for (int i = 1; i < 25; ++i)           // 顺序不能调换！！
        for (int cur = 1; cur <= n; ++cur) // 会调用到比他小次数的其他点！需要一层一层的算
        {
            f[cur][i] = f[f[cur][i - 1]][i - 1]; //  走两个2^(i-1)就是2^i
            w[cur][i] = min(w[cur][i - 1], w[f[cur][i - 1]][i - 1]);
        }
}

int lca(int x, int y)
{
    // 把两个点升至同一高度，再一起跳
    if (find(x) != find(y))
        return -1;
    if (depth[x] < depth[y])
    {
        swap(x, y);
    }
    int ans = 1e9;
    while (depth[x] > depth[y])
    {
        // cout<<w[x][Log[depth[x] - depth[y]]]<<"\n";
        ans = min(ans, w[x][Log[depth[x] - depth[y]]]);
        x = f[x][Log[depth[x] - depth[y]]];
    }
    if (x == y)
        return ans;

    // 两个点同时往上跳，跳到LCA的下一层为止
    for (int i = Log[depth[x]]; i >= 0; --i)
    {
        if (f[x][i] != f[y][i])
        {
            ans = min(ans, w[x][i]);
            ans = min(ans, w[y][i]);
            x = f[x][i];
            y = f[y][i];
        }
    }
    ans = min(ans, w[x][0]);
    ans = min(ans, w[y][0]);
    return ans;
}

/*
先建一棵最大生成树，再用倍增求 LCA来回答询问。
求LCA的方法是先从每一个根节点进行搜索，求出节点深度等信息，
然后利用这些信息进行树上倍增。
*/
int main()
{
    ios::sync_with_stdio(0);
    memset(w, 64, sizeof(w));
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y, w;
        cin >> x >> y >> w;
        e[i] = {x, y, w};
    }
    krustal();
    // for (int node = 1; node <= n; ++node)
    // {
    //     for (int i = head[node]; i > 0; i = g[i].nxt) // 链式前项星遍历
    //     {
    //         cout << node << " " << g[i].to << "\n";
    //     }
    // }
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            depth[i] = 1;
            dfs(i);
            f[i][0] = i;
        }
    }
    //建树
    // for (int node = 1; node <= n; node++)
    // {
    //     cout << node << "\n";
    //     cout << depth[node] << " " << f[node][0] << "\n";
    // }

    // 预处理，常数优化
    for (int i = 2; i <= n; ++i)
    {
        Log[i] = Log[i >> 1] + 1;
    }
    initLCA();
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
    return 0;
}