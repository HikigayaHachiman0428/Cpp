#ifdef ONLINE_JUDGE
	#include <bits/stdc++.h>
#endif
#ifndef ONLINE_JUDGE
#include "bits:stdc++.h"
#endif
using namespace std;	
const int maxn = 1e5+5;
int n, cnt;
pair<int, int> mp[maxn];
int fa[maxn];
bool used[maxn];
void init () {
  for (int i = 0; i <= n; i++) fa[i] = i;  
}

int find(int x) {
  // 寻找x的祖先
  if (fa[x] == x) 
    return x;
  else
    return find(fa[x]); 
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  fa[x] = y; 
}

int main()
{
	#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
	#endif
	memset(used, false, sizeof(used));
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>mp[i].first>>mp[i].second;
	}
	sort(mp+1, mp+1+n);
	init();
	for (int i =1; i<=n; i++){
		int y1 = mp[i].second;
		int pary1 = find(i);
		for (int j =i; j<=n; j++){
			int y2 = mp[j].second;
			if (pary1 != find(j) && y1 <= y2){
				unite(i, j);
			}
		}
	}
	for (int i =1; i<=n; i++){
		if (!used[find(i)]){
			used[find(i)] = true;
			cnt ++;
		}
	}
	cout<<cnt;
}	