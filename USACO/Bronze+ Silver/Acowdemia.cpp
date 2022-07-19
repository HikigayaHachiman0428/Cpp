	#ifndef ONLINE_JUDGE
#include "bits:stdc++.h"
	#endif
	#if ONLINE_JUDGE
#include <bits/stdc++.h>
	#endif
# define int long long
using namespace std;
const int maxn = 1e5 +5;
int n, K, L, ans;
int num[maxn];

bool cmp(int a, int b){
	return a >b;
}

bool check(int h, int k, int l){
	int cnt = 0;
	for (int i =1; i<=h; i++){
		if (num[i] < h){
			int fill = h - num[i];
			if (fill <= k)
				cnt += fill;
			else
				return false;
		}
	}
	return cnt<=k*l;
}

signed main()
{
// 	#ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// 	#endif
	cin>>n>>K>>L;
	for (int i =1; i<=n; i++){
		cin>>num[i];
	}
	sort(num+1,num+1+n, cmp);
	int ll = 1; int rr = n;
	while (ll<=rr){
		int mid = (ll+rr)/2;
		if (check(mid, K, L)){
			ans = max(ans, mid);
			ll = mid+1;
		}
		else{
			rr = mid-1;
		}
	}
	cout<<ans<<endl;
}
