	#ifndef ONLINE_JUDGE
#include "bits:stdc++.h"
	#endif
	#if ONLINE_JUDGE
#include <bits/stdc++.h>
	#endif
using namespace std;	
const int maxn = 5005;
bool cow[maxn][maxn];
int n, ans;
int posx[] = {0,0,0,1,-1};
int posy[] = {0,1,-1,0,0};
void dfs(int x, int y);

bool check(int x, int y){
	if(!cow[x][y]) return false;
	int ret = 0;
	for (int i =0; i<5; i++){
		int newx = x+posx[i];
		int newy = y+posy[i];
		if (cow[newx][newy])
			ret++;
	}
	// cout<<ret<<endl;
	if(ret==4){ 
		// cout<<true<<endl;
		return true;
	}
	// cout<<false<<endl;
	return false;
}

void add(int x, int y){
	cow[x][y] = true;
	for (int i = 0; i<5; i++){
		int newx = x + posx[i];
		int newy = y + posy[i];
		dfs(newx,newy);
	}
}

void dfs(int x, int y){
	if(check(x,y)){
		for (int i =0; i<5; i++){
			int newx = x+posx[i];
			int newy = y+posy[i];
			if (!cow[newx][newy]){
				ans++;
				add(newx, newy);
			}
		}
	}
}


int main()
{
	#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
	#endif
	cin>>n;
	for (int i =1; i<=n; i++){
		int x; int y;
		cin>>x>>y;
		x+=1000; y+=1000;
		if(cow[x][y]) ans--;
		add(x,y);
		cout<<ans<<endl;
	}
}	