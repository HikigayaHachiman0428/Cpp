#include <iostream>
#include <algorithm>
using namespace std;
const int maxm = 100001;
const int maxn = 301;
struct edge
{
    int x, y, w;
} a[maxm];

int f[maxn];
int n, m, ans, cnt;

bool cmp(edge x, edge y)
{
    return x.w < y.w;
}

void init()
{
    for (int i = 0; i <= n; i++)
        f[i] = i;
}

int find(int x)
{
    if (x == f[x])
        return x;
    f[x] = find(f[x]);
    return f[x];
}

void merge(int x, int y, int w)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        f[fy] = fx;
        ans = max(ans, w);
        cnt++;
    }
}

int main()
{
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        a[i] = {x, y, w};
    }
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        merge(a[i].x, a[i].y, a[i].w);
        if (cnt == n - 1)
            break;
    }
    cout << cnt << " " << ans;
}