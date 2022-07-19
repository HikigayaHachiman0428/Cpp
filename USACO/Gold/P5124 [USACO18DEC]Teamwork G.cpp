#include <bits/stdc++.h>
using namespace std;
int n, k;
int s[10001], f[10001];
int main()
{
    iostream::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    for (int i = 1; i <= n; ++i)
    {
        int m = s[i];
        for (int j = i; j >= 1 && i - j + 1 <= k; --j)
        {
            m = max(m, s[j]);
            f[i] = max(f[i], f[j - 1] + (i - j + 1) * m);
        }
    }
    // for (int i = 1; i <= n; ++i)
    //     cout << f[i] << " ";
    cout << f[n];
    return 0;
}