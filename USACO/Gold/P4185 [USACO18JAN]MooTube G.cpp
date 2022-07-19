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
using namespace std;
const int maxn = 1e5+1;
// 排序(离线)并查集解决
int n, B;

int fa[maxn], len[maxn];
void init()
{
	for (int i = 0; i <= n; i++){
		fa[i] = i;
		len[i] = 1;
	}
}

int find(int x)
{
	// 寻找x的祖先
	if (fa[x] == x)
		return x;
	else
		return find(fa[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	fa[x] = y;
	len[y] += len[x];
}

struct snow{
	int h;
	int pos;
}s[maxn];
bool cmp_snow(snow a, snow b){
	return a.h > b.h;
}

struct boot{
	int h;
	int d;
	int i;
}b[maxn];
bool cmp_boot(boot a, boot b){
	return a.h > b.h;
}
bool ans[maxn], vis[maxn];
int main() 
{
//	ios::sync_with_stdio(0); 
	cin>>n>>B;
	for (int i = 1; i <= n; ++i)
	{
		cin>>s[i].h; s[i].pos = i;
	}
	sort(s+1, s+1+n, cmp_snow);
//	for (int i = 1; i<=n; ++i) cout<<s[i].h<<" ";
	for (int i = 1; i <= B; ++i)
	{
		cin>>b[i].h>>b[i].d; b[i].i = i;
	}
	sort(b+1, b+1+B, cmp_boot);
//	for (int i = 1; i<=n; ++i) cout<<b[i].h<<" ";
	init();
	int index = 1;
	int max_len = 1;
	for (int i = 1; i<=n; ++i){
		while(index <= B && s[i].h > b[i].h)
		{
			vis[s[index].pos] = true;
			if (vis[s[index].pos + 1])
			{
				unite(s[index].pos+1, s[index].pos);
				max_len = max(max_len, len[find(s[index].pos)]);
			}
			if (vis[s[index].pos - 1])
			{
				unite(s[index].pos-1, s[index].pos);
				max_len = max(max_len, len[find(s[index].pos)]);
			}
			++index;
		}
		if (b[i].d > max_len)
			ans[b[i].i] = true;
	}
	for (int i = 1; i<=B; ++i)
		cout<<ans[i]<<"\n";
	return 0;
}