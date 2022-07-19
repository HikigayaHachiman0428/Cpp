#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans[25][25];
int xx, yy;
int movex[] = {0,-2, -1, +1, +2, +2, +1, -1, -2};
int movey[] = {0,+1, +2, +2, +1, -1, -2, -2, -1};
int n, m;
bool chk(int x, int y)
{
    for (int i = 0; i < 9; i++)
        if (x == xx + movex[i] && y == yy + movey[i])
            return false;
    return true;
}
int main()
{
    cin >> n >> m >> xx >> yy;
    n++;
    m++;
    xx++;
    yy++;
    ans[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (chk(i, j))
            {
                if (i == 1 && j == 1)
                    continue;
                ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
            }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         cout << ans[i][j] << " ";
    //     cout << endl;
    // }
    cout << ans[n][m];
}