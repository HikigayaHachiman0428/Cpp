#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, K;
int s[401], f[401][401], c[401][401];
signed main()
{
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    iostream::sync_with_stdio(0);
    cin >> n >> K;
    K++;
    int maximum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        maximum = max(maximum, s[i]);
        c[i][i] = 0;
    }
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int m = s[i];
        for (int j = i + 1; j <= n; ++j)
        {
            m = max(m, s[j]);
            for (int k = j; k >= i; --k)
                c[i][j] += m - s[k];
            // cout << c[i][j] << " ";
        }
        // cout<<"\n";
    }
    // f[i][j] = min(f[i][j], f[k][j-1] + s[k+1][i])
    for (int j = 1; j <= K; ++j)
    {
        for (int i = j; i <= n; ++i)
        {
            for (int k = 0; k < i; ++k)
            {
                f[i][j] = min(f[i][j], f[k][j - 1] + c[k + 1][i]);
            }
            // cout << f[i][j] << " ";
        }
        // cout << endl;
    }
    cout << f[n][K];
    return 0;
}