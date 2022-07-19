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
#define ll long long
using namespace std;
const int maxn = 1e5 + 1;
int n;
int len[maxn];	  // 每个folder节点长度
ll path[maxn];	  // 指从每个folder开始回到回到根节点的长度
int folder[maxn]; // 子节点数量
int root;
ll ans;
vector<int> g[maxn];
bool vis[maxn];
void dfs(int node, int fa) // 1.计算从根目录到所有文件的访问路径长度 2.统计每个文件夹的子节点数量
{
	vis[node] = 1;
	if (g[node].size() == 1) // 文件
	{
		
		return;
	}
	folder[node] = 1;
	path[node] = len[node];
	for (int i : g[node])
	{
		if (!vis[i])
		{
			dfs(i, node);
			if (folder[i] != 0) // 不是文件
			{
				folder[node] += folder[i];
				path[node] += path[i];
			}
		}
	}
}

void query(int node, int fa) // 假设每个点为起点的长度
{
	ll cur = path[fa] - folder[node] * len[node] + ;
	ans = min(ans, cur);
	for (int i : g[node])
	{
		if (path[i] != 0 && i != fa)
			query(i, node);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		string s;
		int m;
		cin >> s >> m;
		if (s == "bessie")
			root = i;
		if (m == 0) // 是文件
		{
			len[i] = s.length() + 1;
		}
		else
		{
			len[i] = s.length();
			while (m--) // 文件夹
			{
				int file;
				cin >> file;
				g[i].push_back(file);
				g[file].push_back(i);
			}
		}
	}
	dfs(root, root);
	ans = 1e9;
	path[root] -= len[root];
	query(root, root);
	cout << ans;
	return 0;
}