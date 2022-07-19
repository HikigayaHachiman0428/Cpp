#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
using namespace std;
const int maxn = 1e5 + 1;
int n, k;
vector<int> g[maxn];
int depth[maxn], leaf[maxn];
bool vis[maxn];
int dfs(int cur, int fa)
{
	vis[cur] = true;
	depth[cur] = depth[fa] + 1;
	if (g[cur].size() == 1)
	{
		return leaf[cur] = depth[cur];
	}
	for (int son : g[cur])
	{
		if (!vis[son])
		{
			leaf[cur] = min(leaf[cur], dfs(son, cur));
		}
	}
	return leaf[cur];
}
int ans;
void query(int cur)
{
	if (vis[cur])
		return;
	vis[cur] = true;
	int bessie = depth[cur] - 1;
	int l = leaf[cur] - depth[cur];
	if (bessie >= l)
	{
		// cout << cur << "\n";
		ans++;
	}
	else
	{
		for (int son : g[cur])
			query(son);
	}
}
// 一个dfs预处理每个节点的深度和距离每个点最近的leaf（即出口）的深度，接着再用一个dfs判断是否能在各个节点抓掉bessie,若可以ans++，若不行这在ans的子节点中寻找可以抓到的点
int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	memset(leaf, 0x3f, sizeof(leaf));
	dfs(k, k);
	// cout << "\n";
	// for (int i = 1; i <= n; ++i)
	// 	cout << depth[i] << " " << leaf[i] << "\n";
	memset(vis, false, sizeof(vis));
	query(k);
	cout << ans;
	return 0;
}