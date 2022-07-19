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
const int N = 5000;
int a[1001], b[1001], f[1001][2*N+1];
int main() {
	ios::sync_with_stdio(0); 
	int n;
	cin>>n;
	for (int i = 1; i<=n; ++i)
		cin>>a[i]>>b[i];
	memset(f, 0x3f, sizeof(f));
	f[0][N] = 0;
	for (int i = 1; i<=n; ++i)
	{
		int delta = a[i] - b[i];
		for (int j = N; j>= -N; j--)
		{
			if (j-delta+N >=0 && j+delta+N >=0)
			f[i][j+N]=min(f[i-1][j-delta+N], f[i-1][j+delta+N]+1); // 第i块 不翻 or 翻
		}
	}
	int ans = 1e9;
	for (int j = 0; j <= 5000; ++j)
	{
		ans = min(f[n][j+N], f[n][-j+N]);
		if (ans <= 1000)
		{
			cout<<ans;
			break;
		}
	}
	return 0;
}