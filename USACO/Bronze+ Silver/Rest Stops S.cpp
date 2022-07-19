	#ifndef ONLINE_JUDGE
#include "bits:stdc++.h"
	#endif
	#if ONLINE_JUDGE
#include <bits/stdc++.h>
	#endif
using namespace std;
const int maxn = 1e5+5;
long long ans;
struct stop{
	long long x, c;
}m[maxn];

bool cmp(stop a, stop b){
	return a.c>b.c;
}

long long n;

int main()
{
	#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
	#endif
	long long l, rf, rb;
	cin>>l>>n>>rf>>rb;
	for (int i =1; i<=n; i++){
		cin>>m[i].x>>m[i].c;
	}
	sort(m+1,m+n+1,cmp);
	long long time = 0;
	for (int i =1; i<=n; i++){
		if (rb*m[i].x + time > m[i].x*rf) continue;
		long long eattime = m[i].x*rf - m[i].x*rb - time;
		ans += m[i].c * eattime;
		time += eattime;
	}
	cout<<ans;
}	