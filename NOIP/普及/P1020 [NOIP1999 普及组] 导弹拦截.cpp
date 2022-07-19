#include <bits/stdc++.h>
using namespace std;
const int N=100010;
namespace dp
{
    // o(n^2)
    int a[100], dp[100], trace[100];
    int n;
    void input()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            dp[i] = 1;
            trace[i] = 0;
        }
    }
    void solve()
    {
        for (int i = n - 1; i >= 1; i--)
        {
            int maxlis = 0;
            int maxindex = 0;
            for (int j = i + 1; j <= n; j++)
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

        int pos = 1;
        for (int i = 2; i <= n; i++)
        {
            if (dp[i] > dp[pos])
                pos = i;
        }
        cout << "max=" << dp[pos] << endl;
        while (pos != 0)
        {
            cout << a[pos] << " ";
            pos = trace[pos];
        }
    }
}

namespace ologn
{
    int a[N], d1[N], d2[N], n, len1, len2;
    void input()
    {
        while (cin >> a[++n])
            ;
        n--;                //输入
        len1 = 1, len2 = 1; //初始长度为1
        d1[1] = a[1];       //用于求不上升序列长度
        d2[1] = a[1];       //用于求上升序列长度
    }
    void solve()
    {
        // 不上升序列
        for (int i = 2; i <= n; i++)
        { //从a[2]开始枚举每个数(a[1]已经加进去了)
            if (d1[len1] >= a[i])
                d1[++len1] = a[i]; //如果满足要求(不上升)就加入d1
            else
            { //否则用a[i]替换d1中的一个数
                int p1 = upper_bound(d1 + 1, d1 + 1 + len1, a[i], greater<int>()) - d1;
                d1[p1] = a[i];
            }

        // 上升子序列
            if (d2[len2] < a[i])
                d2[++len2] = a[i]; //同上
            else
            {
                int p2 = lower_bound(d2 + 1, d2 + 1 + len2, a[i]) - d2;
                d2[p2] = a[i];
            }
        }
        cout << len1 << endl
             << len2; //输出
    }
}
using namespace ologn;
int main()
{
    input();
    solve();
    return 0;
}
