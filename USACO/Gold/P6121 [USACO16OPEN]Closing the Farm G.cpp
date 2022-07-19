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
const int maxn = 2 * 100000 + 1;
const int maxm = 2 * 100000 + 1;
// 反推，考虑每次加点的情况
struct edge
{
	int x, y;
} a[maxm];

int f[maxn];
int n, m, ans, cnt;


void init()
{
	for (int i = 0; i <= n; i++)
		f[i] = i;
}

int find(int x)
{
	if (x == f[x])
		return x;
	f[x] = find(f[x]);
	return f[x];
}

void merge(int x, int y, int w)
{
	int fx = find(x);
	int fy = find(y);
	if (fx != fy)
	{
		f[fy] = fx;
		ans += w;
		cnt++;
	}
}

int main() 
{
	ios::sync_with_stdio(0); 
	cin >> n >> m;
	init();
	// input
	for (int i = 1; i <= m; i++)
		{
			int x, y;
			cin >> x >> y;
			a[i] = {x, y};
		}
	
	return 0;
}