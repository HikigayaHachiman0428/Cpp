#include <bits/stdc++.h>
using namespace std;
/*
f[i][j] 前i朵花放入前j个花瓶中的最大美学值
f[i][j] = max(f[i][j], f[i-1][k-1] + a[i][k])
i: 1~F
j: 1~V
k: i<=k<=j

f[i][j] 前i朵花放入前j个花瓶中的最大美学值, 且第i朵花一定放入第j个花瓶
f[i][j] = max(f[i][j], f[i-1][k] + a[i][j])
i-1<=k<=j-1
*/
int n, m;
int w[101][101]; // 花i在瓶j
int f[101][101]; // 前i朵花在前j个花瓶的最大美学值
int p[101];
int main()
{
    iostream::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> w[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= m; ++j)
        {
            for (int k = i; k <= j; ++k)
            {
                if (f[i - 1][k - 1] + w[i][k] > f[i][j])
                {
                    f[i][j] = f[i - 1][k - 1] + w[i][k];
                    p[i] = k;
                }
            }
        }
    cout << f[n][m] << endl;
    for (int i = 1; i <= n; ++i)
        cout << p[n] << " ";
    return 0;
}