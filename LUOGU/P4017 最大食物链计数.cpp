#include <bits/stdc++.h>
#define mod 80112002
using namespace std;
const int maxn = 5005;
long long ans[maxn];
vector<int> g[maxn];
long long indeg[maxn], outdeg[maxn];
bool vis[maxn];
int n, m;

void del(int i)
{
    if (vis[i])
        return;
    vis[i] = true;
    for (int to : g[i])
    {
        indeg[to]--;
        ans[to] += ans[i];
        ans[to] %= mod;
        if (indeg[to] == 0)
            del(to);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, to;
        cin >> x >> to;
        g[x].push_back(to);
        indeg[to]++;
        outdeg[x]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0 && !vis[i])
        {
            ans[i] = 1;
            del(i);
        }
    }
    long long cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << ans[i] << " ";
        if (outdeg[i] == 0)
        {
            cnt += ans[i];
            cnt %= mod;
        }
    }
    cout << cnt % mod;
    return 0;
}