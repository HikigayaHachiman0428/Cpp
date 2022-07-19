#include <iostream>
using namespace std;

const int N = 1e6 + 5;
const int LOGN = 20;

int Log[N] = {-1}, f[N][LOGN + 1], a[N]; // f[i][j] 代表[i, i + 2^j - 1]区间内的最长完美序列的长度
int n, m;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

int main()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = read();
    }
    
    for (int i = 1; i <= n; ++i)
    {
        f[i][0] = 1;
        Log[i] = Log[i >> 1] + 1; // 预处理长度为1~n的log数组
    }
    
    for (int j = 1; j <= LOGN; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]); // st表实现
        }

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        x++; y++;
        int s = Log[y - x + 1];
        cout << max(f[x][s], f[y - (1 << s) + 1][s]) << '\n'; // 按照log将区间划分为两段比较
    }
    return 0;
}
