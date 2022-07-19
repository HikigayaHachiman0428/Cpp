#include <bits/stdc++.h>
using namespace std;

int a[105], dp[105], trace[105];
int n;

void init()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        trace[i] = 0;
    }
}

int getAscend(int ll, int rr)
{
    for (int i = rr - 1; i >= ll; i--)
    {
        int maxlis = 0;
        int maxindex = 0;
        for (int j = i + 1; j <= rr; j++)
        {
            if (a[j] > a[i] && dp[j] > maxlis)
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
    int pos = ll;
    for (int i = ll + 1; i <= rr; i++)
    {
        if (dp[i] > dp[pos])
            pos = i;
    }
    return dp[pos];
}

int getDecend(int ll, int rr)
{
    for (int i = rr - 1; i >= ll; i--)
    {
        int maxlis = 0;
        int maxindex = 0;
        for (int j = i + 1; j <= rr; j++)
        {
            if (a[j] < a[i] && dp[j] > maxlis)
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
    int pos = ll;
    for (int i = ll + 1; i <= rr; i++)
    {
        if (dp[i] > dp[pos])
            pos = i;
    }
    return dp[pos];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = n;
    for (int i = 1; i <= n; i++)
    {
        init();
        ans = min(n - getAscend(1, i) - getDecend(i + 1, n), ans);
    }
    cout<< ans;
    return 0;
}
