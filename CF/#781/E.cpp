#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2*1e5+1;
int a[maxn];
int t;
int main()
{
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		long long sum = 0;
		for (int i =1; i<=n; i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		bool can = true;
		for (int i = 1; i<=n; i++)
		{
			if (a[i] > sum -a[i] + 1)
			{
				can = false;
				break;
			}
		}
		if (can)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;	
	}
	return 0;
}