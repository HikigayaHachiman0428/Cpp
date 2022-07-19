	#ifndef ONLINE_JUDGE
#include "bits:stdc++.h"
	#endif
	#if ONLINE_JUDGE
#include <bits/stdc++.h>
	#endif
using namespace std;
int n;

// 枚举并储存所有可能的A B C, 并统计可能情况
int main()
{
	int t;
	cin>>t;
	while (t--){
			cin>>n;
			int num[8];
			set<int> s;
			for (int i =1; i<=n; i++){
				cin>>num[i];
				s.insert(num[i]);
			}
			for (int i =1; i<=n; i++){
				for (int j =1; j<=n; j++){
					if (i!=j)
						s.insert(abs(num[i]-num[j]));
				}
			}
			for (int x =1; x<=n; x++){
				for (int y=1; y<=n; y++){
					for (int z =1; z<=n; z++){
						if (x==y || y == z || x ==z) continue;
						int fill = num[x]+num[y] - num[z];
						if (fill <= 0) continue;
						s.insert(fill);
						if (!(fill&1)) s.insert(fill/2);
					}
				}
			}
			int ans = 0;
			set<int>:: iterator itr;
			int length = s.size()+1;
			int can[length];
			int i = 0;
			for (itr = s.begin(); itr!=s.end(); itr++){
				i++;
				can[i] = *itr;
			}
			cout<<endl;
			cout<<length<<endl;
			for (int pointer1 = 1; pointer1<=length-2; pointer1++){
				for (int pointer2 = pointer1+1; pointer2<= length-1; pointer2++){
					for (int pointer3 = pointer2+1; pointer3 <= length; pointer3++){
						int a = can[pointer1]; int b = can[pointer2]; int c = can[pointer3];
						bool flag = true;
						for (int i = 1; i<=n; i++){
							if (!(num[i]==a || num[i] == b || num[i] == c || num[i] == a+b||
									num[i]==b+c || num[i] == c+a || num[i] == a+b+c)){
										flag = false;
										break;
							}
						}
						if(flag) {
							ans++;
							// cout<<" "<<a<<" "<<b<<" "<<c<<endl;
						}
					}
				}
			}
			cout<<ans<<endl;
	}
}
