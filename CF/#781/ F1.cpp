#include <bits/stdc++.h>
using namespace std;
int t;
int pl[3005];
int mi[3005];
int main()
{
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            char temp;
            cin >> temp;
            if (temp == '+')
            {
                pl[i]++;
            }
            else
            {
                mi[i]++;
            }
            pl[i] += pl[i - 1];
            mi[i] += mi[i - 1];
        }
        int ans = 0;
        for (int len = 0; len < n; len++)
            for (int i = 1; i + len <= n; i++)
            {
                if (pl[i + len] - pl[i] == mi[i + len] - mi[i])
                    ans++;
                else
                {
                    int dif = mi[i + len] - mi[i] - pl[i + len] + pl[i];
                    if (dif > 0)
                    {
                        int cnt = 0;
                        for (int j = i; j < i + len; j++)
                        {
                            if (mi[j + 1] - mi[j] == 1)
                            {
                                cnt++;
                                j++;
                            }
                        }
                        if (dif <= cnt)
                            ans++;
                    }
                }
            }
        cout << ans << endl;
    }
}