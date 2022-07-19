#include <bits/stdc++.h>
#define inf INT_MAX
#define ll long long
using namespace std;
int n, m[202], r[202];
ll f[202][202];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i];
        m[i + n] = m[i];
        if (i == 1)
        {
            r[n] = m[i];
            r[2 * n] = m[i];
        }
        else
        {
            r[i - 1] = m[i];
            r[i - 1 + n] = m[i];
        }
    }
    for (int i = 2 * n - 1; i >= 1; i--)
        for (int j = i + 1; j <= 2 * n; j++)
        {
            for (int k = i; k < j; k++)
            {
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + m[i] * r[k] * r[j]);
            }
        }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, f[i][i + n - 1]);
    }
    cout << ans;
    return 0;
}