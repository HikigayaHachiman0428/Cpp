#include <bits/stdc++.h>
#define ll long long
const int N = 1e6 + 1;
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
int n, q;
int a[5005];
ll f[5005][5005];
int tong[N * 2], cnt[5005][5005];

signed main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read<int>();
        // cin>>a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cnt[i][j] = tong[-a[i] - a[j] + N];
            tong[a[j] + N]++;
        }
        for (int j = i + 1; j <= n; j++)
            tong[a[j] + N] = 0;
    }
    for (int i = n - 1; i >= 1; i--)
        for (int j = i + 1; j <= n; j++)
        {
            // for (int k = i + 1; k < j; k++)
                f[i][j] = f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1] + cnt[i][j];
            // cout << i << " " << j << " " << f[i][j] << endl;
        }
    while (q--)
    {
        int x, y;
        x = read<int>() ; y = read<int>();
        // cin>>x>>y;
        // cout << f[x][y] << endl;
        printf(f[x][y]);
    }
    return 0;
}