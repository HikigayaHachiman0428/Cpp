#include <bits/stdc++.h>
// 拓扑找环，把每个环中最小的边删掉，总边权减掉删掉的边权就是最后的答案
using namespace std;
/*
4
2 10
3 20
4 30
1 40
*/
const int maxn = 1e5 + 5;
long long ans = 0;
int des[maxn];
int weight[maxn]; // weight[i] 表示从i出发到i所对应的终点所获得的moo
int indeg[maxn];
bool vis[maxn];
int n;

int cycle_length(int i)
{
    vis[i] = true;
    int to = des[i];
    int ret = weight[i];
    while (!vis[to])
    {
        vis[to] = true;
        ret = min(ret, weight[to]);
        to = des[to];
    }
    return ret;
}

void del(int i)
{
    if (vis[i])
        return;
    vis[i] = true;
    int to = des[i];
    indeg[to]--;
    if (indeg[to] == 0)
        del(to);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> des[i];
        indeg[des[i]]++;
        cin >> weight[i];
        ans += weight[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0 && !vis[i])
            del(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans -= cycle_length(i);
        }
    }
    cout << ans;
    return 0;
}