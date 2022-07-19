#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
int a[105][105];
int movex[] = {-1, 0, +1, 0};
int movey[] = {0, 1, 0, -1};
int n, m;
int f[105][105]; // 记忆化搜索

int dfs(int x, int y)
{
    if (x == 0 || y == 0)
        return -INF;
    if (x > n || y > m)
        return -INF;
    // cout << x << " " << y << endl;
    if (f[x][y])
        return f[x][y];
    int ret = 0;
    for (int i = 0; i < 4; i++)
    {
        int newx = x + movex[i];
        int newy = y + movey[i];
        if (a[newx][newy] < a[x][y])
            ret = max(ret, dfs(newx, newy));
    }
    return f[x][y] = ret + 1;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            ans = max(ans, dfs(i, j));
        }
    cout << ans;
    return 0;
}