#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
int n;
int x[151], y[151], group[151];
double f[151][151], maxLen[151], maxPoint[151], ans = 1e9;
bool vis[151], connect[151][151];
double getDist(int a, int b)
{
    return sqrt(pow((x[a] - x[b]), 2) + pow(y[a] - y[b], 2));
}

void dfs(int node, int g)
{
    vis[node] = true;
    group[node] = g;
    for (int i = 1; i <= n; i++)
    {
        if (connect[node][i] && i != node && !vis[i])
        {
            dfs(i, g);
        }
    }
    return;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char b;
            cin >> b;
            connect[i][j] = b == '1' || i == j ? true : false;
            if (i == j)
                f[i][j] = 0;
            else
            {
                if (connect[i][j])
                    f[i][j] = getDist(i, j);
                else
                    f[i][j] = 1e9;
            }
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    int team = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, team);
        team++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            if (group[i] == group[j])
            {
                maxLen[group[i]] = max(maxLen[group[i]], f[i][j]);
                maxPoint[i] = max(f[i][j], maxPoint[i]);
                maxPoint[j] = max(f[i][j], maxPoint[j]);
            }
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            if (group[i] != group[j])
            {
                double dis = getDist(i, j) + maxPoint[i] + maxPoint[j];
                double compare = max(dis, maxLen[group[i]]);
                compare = max(compare, maxLen[group[j]]);
                ans = min(ans, compare);
            }
        }
    cout << fixed << setprecision(6) << ans;
    return 0;
}