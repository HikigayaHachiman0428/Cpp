#include <bits/stdc++.h>
#define p pair<int, int>
using namespace std;
const int N = 5001;
int n, len1, dp[N], trace[N];
p a[N];

bool cmp(p a, p b)
{
    if (a.first != b.first)
        return a.first > b.first;
    else
        return a.second > b.second;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int ca, cb;
        cin >> ca >> cb;
        a[i] = make_pair(ca, cb);
        dp[i] = 1;
        trace[i] = 0;
    }
    sort(a + 1, a + 1 + n, cmp);
    // for (int i = 1; i <= n; i++)
    //     cout << a[i].first << " " << a[i].second << endl;
    for (int i = n - 1; i >= 1; i--)
    {
        int maxlis = 0;
        int maxindex = 0;
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j].second > a[i].second && dp[j] > maxlis)
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