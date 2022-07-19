#include <bits/stdc++.h>
using namespace std;

int f[1001][1001], w[101], c[101];

int main()
{
	int t, m;
	cin >> t >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i] >> c[i]; // 每种药的采摘时间和价值
	}

	// for(int i=1; i<=m; i++) {
	// 	for(int v=t; v>=w[i]; v--) {   // f[v]表示时间不超过v的最大价值
	// 		f[v] = max(f[v-w[i]]+c[i], f[v]);
	// 	}
	// }
	// cout<<f[t]<<endl;

	for (int i = 1; i <= m; i++)
	{
		for (int v = t; v > 0; v--)
		{ // f[v]表示时间不超过v的最大价值
			if (v >= w[i])
			{
				f[i][v] = max(f[i - 1][v], f[i - 1][v - w[i]] + c[i]);
			}
			else
			{
				f[i][v] = f[i - 1][v];
			}
		}
	}
	cout << f[m][t] << endl;

	return 0;
}
