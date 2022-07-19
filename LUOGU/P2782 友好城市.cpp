#include <bits/stdc++.h>
#define p pair<int, int>
using namespace std;
const int maxn = 2e5 + 5;
int n;
p bridge[maxn];
int dp[maxn], trace[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> bridge[i].first >> bridge[i].second;
        dp[i] = 1;    // LIS
        trace[i] = 0; // 上一个数的位置
    }
    sort(bridge + 1, bridge + 1 + n);
    for (int i = n - 1; i >= 1; i--)
    {
        int maxlis = 0;
        int maxindex = 0;
        for (int j = i + 1; j <= n; j++)
        {
            if (bridge[j].second > bridge[i].second && dp[j] > maxlis)
            {
                maxlis = dp[j];
                maxindex = j;
            }
        }

        if (maxlis > 0)
        {
            dp[i] = maxlis + 1;
            trace[i] = maxindex;
        }
    }

    int pos = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dp[i] > dp[pos])
            pos = i;
    }
    cout << dp[pos] << endl;
    return 0;
}