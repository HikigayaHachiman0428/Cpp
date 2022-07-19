	#ifndef ONLINE_JUDGE
#include "bits:stdc++.h"
	#endif
	#if ONLINE_JUDGE
#include <bits/stdc++.h>
	#endif
using namespace std;
const int maxn = 1e5 + 2;
int p[maxn],ansl[maxn],ansr[maxn];
bool painted[27];	
int n, q;

int main()
{
	#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
	#endif
	cin>>n>>q;
	for (int i =1; i<= n; i++){
		char input;
		cin>>input;
		p[i] = int (input)-64;
	}
	int ans = 0;
	memset(painted,false,sizeof(painted));
	for (int i =1; i<=n; i++){
		if (p[i-1]<p[i]){
			ans ++;
			painted[p[i]] = true;
		}
		else{
			if (!painted[p[i]]){
				ans++;
				painted[p[i]] = true;
			}
			for (int j=p[i]+1; j<=27;j++)
				painted[j] = false;
		}
		ansl[i] = ans;
	}
	ans =0;
	memset(painted,false,sizeof(painted));
	for (int i = n; i>=1; i--){
		if (p[i+1]<p[i]){
			ans ++;
			painted[p[i]] = true;
		}
		else{
			if (!painted[p[i]]){
				painted[p[i]] = true;
				ans++;
			}
			for (int j=p[i]+1; j<=27;j++)
				painted[j] = false;
		}
		ansr[i] = ans;
	}
	for (int index =1; index <=q; index ++){
		ans = 0;
		int ll, rr;
		cin>>ll>>rr;
		if (ll > 1){
			ans += ansl[ll -1];	
		}
		if (rr<n){
			ans+=ansr[rr+1];
		}
		cout<<ans<<endl;
	}
}	