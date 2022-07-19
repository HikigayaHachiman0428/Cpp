#include <bits/stdc++.h>
#define ll long long
using namespace std;
namespace int128
{
    inline __int128 read()
    {
        __int128 x = 0, f = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                f = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = x * 10 + ch - '0';
            ch = getchar();
        }
        return x * f;
    }

    inline void write(__int128 x)
    {
        if (x < 0)
        {
            putchar('-');
            x = -x;
        }
        if (x > 9)
            write(x / 10);
        putchar(x % 10 + '0');
    }
}
using namespace int128;
int n, K;
__int128 a[41][41], f[41][7];
char s[41];
int main()
{
    iostream::sync_with_stdio(false);
    cin >> n >> K;
    cin >> s;
    for (int i = 1; i <= n; i++)
        a[i][i] = s[i - 1] - '0';
    for (int i = n; i >= 1; --i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            a[i][j] = a[j][i] = a[i][i] * pow(10, j - i) + a[i + 1][j];
        }
    }
    for (int i = 1; i <= n; ++i)
        f[i][0] = a[1][i];
    for (int k = 1; k <= K; ++k)
        for (int j = k; j <= n; ++j)
        {
            // f[j][k] = f[j][k - 1];
            for (int i = 1; i < j; ++i)
            {
                f[j][k] = max(f[j][k], f[i][k - 1] * a[i + 1][j]);
            }
        }
    write(f[n][K]);
    return 0;
}