#include <bits/stdc++.h>
#define inf INT_MAX / 3
using namespace std;
int n;
int f[305][305], a[305];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // memset(f, inf, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        f[i][i] = 1;
    }
    for (int i = n - 1; i >= 1; i--)
        for (int j = i + 1; j <= n; j++)
        {
            // f[i][j] = inf;
            f[i][j] = f[i][j - 1];
            if (a[i] != a[j])
                f[i][j]++;
            // cout << a[i] << " " << a[j] << " " << f[i][j - 1] << f[i][j] << endl;
            for (int k = i; k < j; k++)
            {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
            }
        }
    cout << f[1][n];
    return 0;
}