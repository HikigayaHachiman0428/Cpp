#include <bits/stdc++.h>
#define mod 1000000007;
using namespace std;
/*
f[i][j][k] 表示A串的前i个字符，选了j个字符串，用了k个子串的方案数


f2[i][j][k]表示A串的前i个字符，选了j个字符串，且必选第i个字符，用了k个子串的方案数

第i个字符和前面的字符合并成一个子串    第i个字符开始单独作为一个子串
f2[i][j][k] = f2[i-1][j-1][k] + f[i-1][j-1][k-1]


不选第i个字符    选第i个字符
f[i][j][k] = f[i-1][j][k] + f2[i][j][k]
*/
int n, m, k;
char a[1005], b[1005];
int f[1001][201][201], f2[1001][201][201];

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= m; j++)
        cin >> b[j];
    f[0][0][0] = 1;
    f2[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = min(m, i); j >= 1; j--)
            for (int v = min(k, j); v >= 1; v--)
            {
                if (a[i] == b[j])
                {
                    f2[i][j][v] = f2[i - 1][j - 1][v] + f[i - 1][j - 1][v - 1];
                    f2[i][j][v] %= mod;
                    f[i][j][v] = f[i - 1][j][v] + f2[i][j][v];
                    f[i][j][v] %= mod;
                }
                else
                {
                    f[i][j][v] = f[i - 1][j][v];
                    f[i][j][v] %= mod;
                }
            }
    // cout << f[0][0][0] << endl;
    // for (int i = 0; i <= n; i++)
    //     for (int j = 0; j <= m; j++)
    //         for (int v = 0; v <= k; v++)
    //             cout << "f[" << i << "][" << j << "][" << v << "] = " << f[i][j][v] << endl;
    cout << f[n][m][k];
    return 0;
}