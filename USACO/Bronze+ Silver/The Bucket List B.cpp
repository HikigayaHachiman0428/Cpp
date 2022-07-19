#include <iostream>
#include <algorithm>
using namespace std;
const int maxN = 105;
int prefix[maxN];
int main(){
  int n;
	cin>>n; // n个区间，m个位置
  int last = 0;
	for (int index =1; index <=n; index++){
		int i; int j; int b;
		cin>>i>>j>>b;
		prefix[i]+= b;
		prefix[j]-= b;
    last = max(last, j);
	}
  int ans = 0;
  ans = max(ans, prefix[0]);
	for (int i =1; i<=last; i++){
    prefix[i] += prefix[i-1];
    ans = max (ans, prefix[i]);
	}
  cout<<ans<<endl;
}
