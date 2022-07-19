#include <iostream>
const int mod = 1000000007;
using namespace std;
int n, m, k, s[5001], c[5001], demand[27];
int f[5001][5001], method[5001];
// 递推计算对于每种长度，每种韵脚的方案数，最后根据题目要求进行统计

int getKSM(int a, int b, int k)
{
    int ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans = (1LL * ans * a) % k;
        }
        a = (1LL * a * a) % k;
        b /= 2;
    }
    return ans % k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i] >> c[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        char temp;
        cin >> temp;
        ++demand[temp - 'A' + 1];
    }
    method[0] = 1;
    for (int i = 1; i <= k; ++i) // length
    {
        for (int j = 1; j <= n; ++j) // word
        {
            if (s[j] <= i)
            {
                f[i][c[j]] = (f[i][c[j]] + method[i - s[j]]) % mod;
                method[i] = (method[i] + method[i - s[j]]) % mod;
            }
        }
    }
    long long ans = 1;
    for (int i = 1; i <= 26; ++i)
    {
        if (demand[i])
        {
            int sum = 0;
            for (int j = 1; j <= n; ++j)
            {
                if (f[k][j])
                    sum = (sum + getKSM(f[k][j], demand[i], mod)) % mod;
            }
            ans = ans * sum % mod;
        }
    }
    cout << ans;
    return 0;
}