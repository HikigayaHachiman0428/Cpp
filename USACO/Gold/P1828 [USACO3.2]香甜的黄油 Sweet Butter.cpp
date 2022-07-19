#include <bits/stdc++.h>
using namespace std;
namespace fastIO
{
    template <typename T>
    inline T read()
    {
        T X = 0;
        bool flag = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = 0;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            X = (X << 1) + (X << 3) + ch - '0';
            ch = getchar();
        }
        if (flag)
            return X;
        return ~(X - 1);
    }

    template <typename T>
    inline void printf(T X)
    {
        if (X < 0)
        {
            putchar('-');
            X = ~(X - 1);
        }
        int s[50], top = 0;
        while (X)
        {
            s[++top] = X % 10;
            X /= 10;
        }
        if (!top)
            s[++top] = 0;
        while (top)
            putchar(s[top--] + '0');
        putchar('\n');
        return;
    }
}
using namespace fastIO;
int n, p, c;
int cow[501], f[1451][1451];

int main()
{
    n = read<int>();
    p = read<int>();
    c = read<int>();
    for (int i = 1; i <= n; i++)
        cow[i] = read<int>();
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= p; i++)
        f[i][i] = 0;
    for (int i = 1; i <= c; i++)
    {
        int a = read<int>();
        int b = read<int>();
        int w = read<int>();
        f[a][b] = w;
        f[b][a] = w;
    }
    for (int k = 1; k <= p; k++)
        for (int i = 1; i <= p; i++)
            for (int j = 1; j <= p; ++j)
            {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
    long long ans = 1e9;
    for (int i = 1; i <= p; i++)
    {
        long long sum = 0;
        for (int j = 1; j <= n; j++)
        {
            // cout << f[i][cow[j]] << " ";
            sum += f[i][cow[j]];
        }

        // cout << " " << i << " " << sum << endl;
        ans = min(ans, sum);
    }
    printf(ans);
    return 0;
}