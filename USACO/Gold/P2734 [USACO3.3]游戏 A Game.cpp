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
}
using namespace fastIO;
int n, a[101], p[101], f[101][101];
int main()
{
    n = read<int>();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = read<int>();
        p[i] = p[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i)
        f[i][i] = a[i];
    for (int i = n - 1; i >= 0; --i)
        for (int j = i + 1; j <= n; ++j)
        {
            int max1 = p[j] - p[i - 1] - f[i + 1][j];
            int max2 = p[j] - p[i - 1] - f[i][j - 1];
            f[i][j] = max(max1, max2);
        }
    cout << f[1][n] << " " << p[n] - f[1][n];
    return 0;
}
