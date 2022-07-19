#include <bits/stdc++.h>
#define inf INT_MAX / 3
using namespace std;
int n, f[205][205], fmi[205][205], p[205];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        p[i + n] = p[i];
    }
    int len = n;
    n *= 2;
    for (int i = 2; i <= n; i++)
    {
        p[i] += p[i - 1];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j - i < n && j <= n; j++)
        {
            fmi[i][j] = inf;
            for (int k = i; k < j; k++)
            {
                fmi[i][j] = min(fmi[i][j], fmi[i][k] + fmi[k + 1][j] + (p[j] - p[i - 1]));
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + p[j] - p[i - 1]);
            }
        }
    }
    int min_ans = inf;
    int max_ans = 0;
    for (int i = 1; i <= len; i++)
    {
        min_ans = min(min_ans, fmi[i][i + len - 1]);
        max_ans = max(max_ans, f[i][i + len - 1]);
    }
    cout << min_ans << "\n"
         << max_ans;
    return 0;
}