#include <bits/stdc++.h>
using namespace std;
int n, K;
char fj[100001];
int f[100001][21][5]; // 前i轮，换了j轮，这轮用k手势
// 1 是石头，2是剪刀，3是布
int check(char a, int b)
{
    if (a == 'H')
    {
        if (b == 1)
            return 0;
        if (b == 3)
            return 0;
        if (b == 2)
            return 1;
    }
    if (a == 'S')
    {
        if (b == 2)
            return 0;
        if (b == 1)
            return 0;
        if (b == 3)
            return 1;
    }
    if (a == 'P')
    {
        if (b == 3)
            return 0;
        if (b == 2)
            return 0;
        if (b == 1)
            return 1;
    }
}
int main()
{
    iostream::sync_with_stdio(0);
    cin >> n >> K;
    for (int i = 1; i <= n; ++i)
    {
        cin >> fj[i];
    }
    for (int i = 0; i <= K; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            f[1][i][j] = check(fj[1], j);
        }
    }
    for (int i = 1; i <= 3; ++i)
        for (int j = 2; j <= n; ++j)
        {
            f[j][0][i] = f[j - 1][0][i] + check(fj[j], i);
        }
    for (int j = 1; j <= K; ++j)
        for (int i = 2; i <= n; ++i)
        {
            for (int k = 1; k <= 3; ++k)
            {
                int w = check(fj[i], k);
                for (int s = 1; s <= 3; ++s)
                {
                    if (s == k)
                    {
                        f[i][j][k] = max(f[i][j][k], f[i - 1][j][s] + w);
                        continue;
                    }
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][s] + w);
                }
                // cout<<f[i][j][k]<<" ";
            }
            // cout << endl;
        }
    int ans = 0;
    for (int i = 1; i <= 3; i++)
        ans = max(ans, f[n][K][i]);
    cout << ans;
    return 0;
}