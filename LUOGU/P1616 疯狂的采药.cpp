#include <bits/stdc++.h>
#define int long long
const int maxm = 1e7 + 2;
using namespace std;
int t, m;
int cost[maxm], w[maxm];
int f[maxm];
signed main()
{
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
        cin >> cost[i] >> w[i];
    for (int i = 1; i <= m; i++)
        for (int j = cost[i]; j <= t; j++)
        {
            f[j] = max(f[j], f[j - cost[i]] + w[i]);
        }
    cout << f[t];
}