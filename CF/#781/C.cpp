#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int t;
string s;
int cnt[26];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>s;
		if (s.length() == 0){
			cout<<0<<endl;
			continue;
		}
		long long ans = 0;
		for (int i = 0; i<s.length(); i+=2)
		{
			if (s[i] != s[i+1])
			{
				memset(cnt, 0, sizeof(cnt));
				int sum = 0;
				while(s[i]!=s[i+1] && i+2<s.length())
				{
					cnt[s[i] - 'a']++;
					cnt[s[i+1]- 'a']++;
					i+=2;
					sum+=2;
				}
				int MAX = 0;
				for (int j:cnt)
				{
					MAX = max(MAX, j);
				}
				ans+=(sum-MAX);
				if (MAX% 2 == 1)
					ans++;
			}	
		}
		if (s.length() % 2 ==1)
			ans ++;
		cout<<ans<<endl;
	}
	return 0;
}