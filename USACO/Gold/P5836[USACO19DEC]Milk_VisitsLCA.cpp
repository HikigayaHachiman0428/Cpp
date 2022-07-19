#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 1;
int n, m;
int t[maxn];
vector<int> g[maxn];
struct query
{
    int c, index;
};
vector<query> q[maxn];
int ans[maxn];  // 对于每个query的答案
int last[maxn]; // 每个节点每种奶牛上次出现的位置
bool vis[maxn];
// 若所需求的奶牛的子节点在两个重点的前面的出现地点不同，则满足要求
// dfs标记每种奶牛上次出现的地点

void dfs(int cur)
{
    vis[cur] = true;
    // cout << cur << "\n";
    // 当前点的所有query
    int temp = last[t[cur]];
    if (q[cur].size() != 0)
    {
        for (query i : q[cur])
        {
            int index = i.index;
            int c = i.c;
            if (c == t[cur])
            {
                ans[index] = 1;
                continue;
            }
            // cout << "\n"
                //  << index << " " << c << " " << last[c] << "\n";
            if (ans[index] == -1) // 如果这个query是第一次访问
            {
                ans[index] = last[c];
            }
            else
            {
                ans[index] = last[c] != ans[index];
            }
        }
    }
    // 所有子节点query
    if (g[cur].size() != 0)
    {
        for (int son : g[cur])
        {
            if (!vis[son])
            {
                last[t[cur]] = son;
                dfs(son);
            }
        }
    }
    last[t[cur]] = temp;
}

int main()
{
    memset(ans, -1, sizeof(ans));
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    for (int i = 1; i <= n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= m; ++i)
    {
        int x, y, c;
        cin >> x >> y >> c;
        query temp;
        temp.c = c;
        temp.index = i;
        q[x].push_back(temp);
        q[y].push_back(temp);
    }
    dfs(1);
    for (int i = 1; i <= m; ++i)
        cout << ans[i];
    return 0;
}