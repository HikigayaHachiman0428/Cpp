#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int w[105][105], c[105][105], f[105];
int main()
{
    cin >> t >> n >> m;
    for (int i = 1; i <= t; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            w[i][j] = c[i][j] - c[i][j - 1];
        }
    for (int day = 1; day <= t; day++)
    {
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++)
            for (int j = c[day][i]; j <= m; j++)
                f[j] = max(f[j], f[j - c[day][i]] + w[day][i]);
        m += f[m];
    }
    cout << m;
    return 0;
}