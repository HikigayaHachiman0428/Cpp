#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 2;
int t;
int a[maxn];
int main()
{
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long product = 1;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			product *= a[i];
		}
		int first = 0;
		int second = 0;
		
		if (product < 0)
		{
			for (int j = 1; j <= n / 2; j++)
			{
				if (a[j] <= 0 || a[n - j + 1] <= 0)
				{
					if (a[j] < 0 && a[n - j + 1] < 0)
					{
						if (a[j] > a[n - j + 1])
						{
							first = j;
							second = 0;
						}
						else
						{
							first = 0;
							second = j;
						}
					}
					else
					{
						if (a[j] <= 0)
						{
							first = j;
							second = 0;
						}
						else
						{
							first = 0;
							second = j;
						}
					}
					break;
				}
			}
		}
		cout << first << " " << second << endl;
	}
	return 0;
}