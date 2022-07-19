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
int f[101];

int main()
{
    int t = read<int>();
    while(t--)
    {
        int n = read<int>();
        int a[n+1];
        int Max = 0;
        for (int i = 1; i<=n; ++i)
        {
            a[i] = read<int>();
            Max = max(Max, a[i]);
        }
        memset(f, -63, sizeof(f));
        f[0] = 0;
        for (int i = 1; i<=n; ++i)
            for (int j = a[i]; j<=Max; j+=a[i])
                f[i] = max(f[i], f[i-a[i]] + 1);
        for (int )
    }
}
