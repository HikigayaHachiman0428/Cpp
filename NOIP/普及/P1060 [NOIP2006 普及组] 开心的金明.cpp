#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[26], w[26];
long long f[30005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> c[i] >> w[i];
    for (int i = 1; i <= m; i++)
        for (int j = n; j >= c[i]; j--)
        {
            f[j] = max(f[j], f[j - c[i]] + c[i] * w[i]);
        }
    cout << f[n];
    return 0;
}