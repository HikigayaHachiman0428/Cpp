// #include "bits:stdc++.h"
#include <bits/stdc++.h>
using namespace std;	
const int maxn = 1005;
int n;
int line[maxn][2],column[maxn][2]; // [][0]为偶数，[][1]为奇数

int main()
{
	#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
	#endif
	cin>>n;
	for (int i =1; i<=n; i++){
		for (int j =1; j<=n; j++){
			int cow;
			cin>>cow;
			line[i][j%2] +=cow;
			column[j][i%2] +=cow;
		}
	}
	int line_based =0, column_based =0;
	for (int i =1; i<=n; i++){
		line_based+=max(line[i][0],line[i][1]);
		column_based+=max(column[i][0],column[i][1]);
	}
	int ans = max(line_based, column_based);
	cout<<ans<<endl;
}	