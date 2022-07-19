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
int n, c;
int main()
{
    return 0;
}
