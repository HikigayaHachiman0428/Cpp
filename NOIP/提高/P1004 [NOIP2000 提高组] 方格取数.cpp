#include <bits/stdc++.h>
using namespace std;
int n, a[10][10], f[10][10][10][10];
int main()
{
    iostream::sync_with_stdio(false);
    cin >> n;
    int x, y, w;
    while (cin >> x >> y >> w)
    {
        if (x == 0 && y == 0 && w == 0)
            break;
        a[x][y] = w;
    }
    for (int x1 = 1; x1 <= n; ++x1)
        for (int y1 = 1; y1 <= n; ++y1)
            for (int x2 = 1; x2 <= n; ++x2)
                for (int y2 = 1; y2 <= n; ++y2)
                {
                    // 上上
                    f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2], f[x1 - 1][y1][x2 - 1][y2] + a[x1][y1] + a[x2][y2]);
                    // 左左
                    f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2], f[x1][y1 - 1][x2][y2 - 1] + a[x1][y1] + a[x2][y2]);
                    //上左
                    f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2], f[x1 - 1][y1][x2][y2 - 1] + a[x1][y1] + a[x2][y2]);
                    //左上
                    f[x1][y1][x2][y2] = max(f[x1][y1][x2][y2], f[x1][y1 - 1][x2 - 1][y2] + a[x1][y1] + a[x2][y2]);
                    if (x1 == x2 && y1 == y2)
                        f[x1][y1][x2][y2] -= a[x1][y1];
                }
    cout << f[n][n][n][n];
    return 0;
}