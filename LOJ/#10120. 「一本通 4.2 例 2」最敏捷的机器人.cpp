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
const int N = 1e6 + 5;
const int LOGN = 20;

int Log[N] = {-1}, fMax[N][LOGN + 1], fMin[N][LOGN + 1], a[N]; // f[i][j] 代表第
int n, m;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
		while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
		return x*f;
	}
	
int main() {
	//  ios::sync_with_stdio(false);
	//  cin.tie(0);
	
	n = read(); m = read();
	for(int i=1; i<=n; ++i) {
		a[i] = read();
	}
	
	for(int i=1; i<=n; ++i) {
		fMax[i][0]=a[i]; fMin[i][0]=a[i]; 
		Log[i]=Log[i>>1] + 1;  // 预处理长度为1~n的log数组
	}
	
	for (int j = 1; j<=LOGN; ++j)
		for (int i = 1; i + (1 << j) - 1<=n; ++i)
			{
				fMax[i][j] = max(fMax[i][j-1], fMax[i+ (1<<(j-1))][j-1]); // st表实现
				fMin[i][j] = min(fMin[i][j-1], fMin[i+ (1<<(j-1))][j-1]);
			}
	
	while(m--) {
		int x, y;
		cin>>x>>y;
		int s = Log[y - x + 1];
		cout<< max(fMax[x][s], fMax[y - (1 << s) + 1][s]) << ' ' 
			<< min(fMin[x][s], fMin[y - (1 << s) + 1][s]) << '\n'; // 按照log将区间划分为两段比较
	}
	return 0;
}