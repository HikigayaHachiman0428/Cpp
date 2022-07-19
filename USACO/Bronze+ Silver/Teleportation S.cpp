	#ifndef ONLINE_JUDGE
#include "bits:stdc++.h"
	#endif
	#if ONLINE_JUDGE
#include <bits/stdc++.h>
	#endif
using namespace std;
const int maxn = 1e5+5;	
int n;
int rr[maxn], ll[maxn];
long long ans, left, right;

signed main()
{
	#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
	#endif
	cin>>n;
	for (int i =1; i<=n; i++){
		int x; int y;
		cin>>x>>y;
		if (x<0 && y<0 || x>0 && y>0)
			ans+=abs(x-y);
		else{
			if (x>0 and )
		}
	}
}	