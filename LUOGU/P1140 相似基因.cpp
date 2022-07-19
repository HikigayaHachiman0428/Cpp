#include <bits/stdc++.h>
using namespace std;
int n1, n2;
int w[5][5] = {
    {5, -1, -2, -1, -3},
    {-1, 5, -3, -2, -4},
    {-2, -3, 5, -2, -2},
    {-1, -2, -2, 5, -1},
    {-3, -4, -2, -1, -INT_MAX}};
int a[101], b[101];
int f[101][101];
int main()
{
    iostream::sync_with_stdio(false);
    cin >> n1;
    for (int i = 1; i <= n1; ++i)
    {
        char c;
        cin >> c;
        switch (c)
        {
        case ('A'):
            a[i] = 0;
            break;
        case ('C'):
            a[i] = 1;
            break;
        case ('G'):
            a[i] = 2;
            break;
        case ('T'):
            a[i] = 3;
            break;
        }
    }
    cin >> n2;
    for (int i = 1; i <= n2; ++i)
    {
        char c;
        cin >> c;
        switch (c)
        {
        case ('A'):
            b[i] = 0;
            break;
        case ('C'):
            b[i] = 1;
            break;
        case ('G'):
            b[i] = 2;
            break;
        case ('T'):
            b[i] = 3;
            break;
        }
    }
    memset(f, -63, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n2; ++i)
        f[0][i] = f[0][i - 1] + w[4][b[i]];
    for (int i = 1; i <= n1; ++i)
        f[i][0] = f[i - 1][0] + w[a[i]][4];
    for (int i = 1; i <= n1; ++i)
        for (int j = 1; j <= n2; ++j)
        {
            f[i][j] = f[i - 1][j - 1] + w[a[i]][b[j]];
            f[i][j] = max(f[i][j], f[i][j - 1] + w[4][b[j]]);
            f[i][j] = max(f[i][j], f[i - 1][j] + w[a[i]][4]);
        }
    cout << f[n1][n2];
    return 0;
}