#include <bits/stdc++.h>
using namespace std;
int a[25], dp[25], trace[25];
bool connect[25][25];
// 对于f[i], f[i] = max(a[i] + f[j]), (j>i 且i j 联通), f[n] = a[n]
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = a[i];
        trace[i] = 0;
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= n - i; j++)
            cin >> connect[i][i + j];
    for (int i = n - 1; i >= 1; i--)
    {
        int maxlis = 0;
        int maxindex = 0;
        for (int j = i + 1; j <= n; j++)
        {
            if (dp[j] > maxlis && connect[i][j])
            {
                maxlis = dp[j];
                maxindex = j;
            }
        }
        if (maxlis > 0)
        {
            dp[i] = maxlis + a[i];
            trace[i] = maxindex;
        }
    }

    int pos = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dp[i] > dp[pos])
            pos = i;
    }
    int ans = pos;
    while (pos != 0)
    {
        cout << pos << " ";
        pos = trace[pos];
    }
    cout << endl
         << dp[ans];
    return 0;
}
