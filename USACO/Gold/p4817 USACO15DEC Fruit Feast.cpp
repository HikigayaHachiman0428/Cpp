#include <iostream>
#include <algorithm>
using namespace std;
int f[5000005];
int a, b, t;

int main()
{
	cin>>t>>a>>b;
	for (int v = a; v <= t; v++)
		f[v] = max(f[v], f[v-a] + a); 
	for (int v = b; v <= t; v++)
		f[v] = max(f[v], f[v-b] + b);
	for (int v = min(a,b); v <= t; v++)
		f[v/2] = max(f[v/2], f[v]/2);
	for (int v = min(a,b); v<= t; v++)
	{
		if (v >= a)
			f[v] = max(f[v], f[v-a] + a);
		if (v >= b)
			f[v] = max(f[v], f[v-b] + b);
	}
	cout<<f[t];
}