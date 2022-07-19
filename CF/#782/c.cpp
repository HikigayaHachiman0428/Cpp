#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 3;
int t;
int prefix[maxn], num[maxn];
int main()
{
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        for (int i = 1; i <= n; i++)
        {
            cin >> num[i];
            prefix[i] += prefix[i - 1] + num[i];
        }
        // for (int i =1; i<=n; i++)
        //     cout<<prefix[i]<<" ";
        long long ans = 0;
        int index = 0;
        for (int i = 1; i <= n; i++)
        {
            cout << index << " " << num[i] << endl;
            ans += (num[i] - index) * b;
            cout << "No move = " << (prefix[num[i]] - prefix[index]) * b << endl;
            cout << "Move = " << (num[i] - index) * a << endl;
            if ((prefix[num[i]] - prefix[index]) * b < (num[i] - index) * a)
            {
                ans += (num[i] - index) * a;
                index = num[i];
            }
        }
        cout << ans << endl;
    }
}