	#ifndef ONLINE_JUDGE
#include "bits:stdc++.h"
	#endif
	#if ONLINE_JUDGE
#include <bits/stdc++.h>
	#endif
#define int long long
using namespace std;	
const int maxn = 200001;
int k, m, n;
bool vis[maxn];
struct grass{
	int i,p, t, closest_cow;
}gt[maxn], gp[maxn];

bool tcmp(grass a, grass b){
	return a.t>b.t;
}

priority_queue<int>p;

signed main()
{
	#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
	#endif
	cin>>k>>m>>n;
	for (int i =0; i<k; i++){
		cin>>gp[i].p>>gp[i].t;
		gt[i].p = gp[i].p; gt[i].t = gp[i].t;
		gt[i].i=i;
		gt[i].closest_cow=gp[i].closest_cow=1e9;
	}
	int ll =0; int rr = 1; int last;
	for (int i = 0; i<m; i++){
		int cow; cin>>cow;
		if(i==m-1) last=cow;
		if(cow > gp[rr].p){
			ll++;
			rr++;
		}
		int left = gp[ll].p;
		int right = gp[rr].p;
		gp[ll].closest_cow = gt[ll].closest_cow = min(gp[ll].closest_cow, abs(left-cow));
		gp[rr].closest_cow = gt[rr].closest_cow = min(gp[rr].closest_cow,abs(right-cow));
	}
	rr++;
	while (rr<k){
		gp[rr].closest_cow = gt[rr].closest_cow = abs(gp[rr].p-last);
		rr++;
	}
	sort(gt, gt+k,tcmp);
	int index = 0;
	memset(vis,false,sizeof(vis));
	while(index<k){
		if(!vis[gt[index].i]){
			vis[gt[index].i] = true;
			int push = gt[index].t;
			int i = gt[index].i;
			while(i-1>=0 && abs(gp[--i].p-gt[index].p)<gt[index].closest_cow){
				push+=gp[i].t;
				vis[i] = true;
			}
			i = gt[index].i;
			while(i+1<k && abs(gp[++i].p-gt[index].p)<gt[index].closest_cow){
				push+=gp[i].t;
				vis[i] = true;
			}
			p.push(push);
		}
		index++;
	}
	long long ans = 0;
	// while(!p.empty()){
	// 	cout<<p.top()<<endl;
	// 	p.pop();
	// }
	for (int i =1; i<=n; i++){
		ans+= p.top();
		p.pop();
	}
	cout<<ans<<endl;
}	