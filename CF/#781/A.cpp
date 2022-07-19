#include <iostream>
using namespace std;
int n;
int main()
{
	cin>>n;
	for (int i =1; i<=n; i++)
	{
		int a, b;
		cin>>a>>b;
		if (a==0){
			cout<<1<<endl;
			continue;
		}
		cout<<a*1 + b*2 + 1<<endl;
	}
}