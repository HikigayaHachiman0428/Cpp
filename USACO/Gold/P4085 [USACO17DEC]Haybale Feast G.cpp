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
#define int long long
using namespace std;
const int maxn = 1e5+1;
const int LOGN = 20;
int n, m;
long long w[maxn], s[maxn],  f[maxn][LOGN + 1];
int Log[maxn] = {-1};
signed main() 
{
	ios::sync_with_stdio(0); 
	cin>>n>>m;
	for (int i = 1; i<=n; ++i)
	{
		cin>>w[i]>>s[i];
		w[i]+=w[i-1];
	}
	for (int i = 1; i <= n; ++i)
	{
		f[i][0] = s[i];
		Log[i] = Log[i >> 1] + 1; // 预处理长度为1~n的log数组
	}
	for (int j = 1; j <= LOGN; ++j)
		for (int i = 1; i + (1 << j) - 1 <= n; ++i)
		{
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]); // st表实现
		}
	int ll = 1; int rr; long long ans = 1e9;
	for (rr = 1; rr<=n; rr++)
	{
		while(w[rr] - w[ll-1] >= m)
		{
			int s = Log[rr - ll + 1];
			ans = min(ans , max(f[ll][s], f[rr - (1 << s) + 1][s])); // 按照log将区间划分为两段比较
//			cout<<ll<<" "<<rr<<" "<<max(f[ll][s], f[rr - (1 << s) + 1][s])<<"\n";
			ll++;
		}
	}
	cout<<ans;
	return 0;
}