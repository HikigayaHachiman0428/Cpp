#include <bits/stdc++.h>
using namespace std;
const int maxn = 255;
int n, b, snow[maxn], f[maxn], d[maxn], ans;
bool vis[maxn][maxn];

void dfs(int block, int boot)
{
	if (vis[block][boot])
		return;
	vis[block][boot] = true;
	if (block == n)
	{
		ans = min(ans, boot - 1);
		return;
	}
	if (snow[block] > f[boot])
		return;
	for (int i = 1; i <= d[boot]; i++)
	{
		if (block + i > n)
			break;
		dfs(block + i, boot);
	}
	for (int i = boot; i <= b; i++)
	{
		dfs(block, i);
	}
}

int main()
{
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);
	cin >> n >> b;
	ans = 1e9;
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i++)
	{
		cin >> snow[i];
	}
	for (int i = 1; i <= b; i++)
	{
		cin >> f[i] >> d[i];
	}
	dfs(1, 1);
	cout << ans << endl;
}