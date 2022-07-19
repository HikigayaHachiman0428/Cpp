#include <bits/stdc++.h>
using namespace std;
int state[2025], num[2025], f[10][1025][82];
int n, k, cnt;

void dfs(int x, int count, int cur)
{
    if (x >= n)
    {
        state[++cnt] = cur;
        num[cnt] = count;
        return;
    }
    dfs(x + 1, count, cur);
    dfs(x + 2, count + 1, cur + (1 << x));
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    //枚举每行可能状态
    dfs(0, 0, 0);
    // cout << cnt << endl;
    for (int i = 1; i <= cnt; ++i)
        f[1][i][num[i]] = 1;
    for (int i = 2; i <= n; ++i)
        for (int cur = 1; cur <= cnt; ++cur)
            for (int pre = 1; pre <= cnt; ++pre)
            {
                if (state[cur] & state[pre])
                    continue;
                if ((state[cur] << 1) & state[pre])
                    continue;
                if (state[cur] & (state[pre] << 1))
                    continue;
                for (int king = num[cur]; king <= k; ++king)
                    f[i][cur][king] += f[i - 1][pre][king - num[cur]];
            }
    long long ans = 0;
    for (int i = 1; i <= cnt; ++i)
        ans += f[n][i][k];
    cout << ans;
    return 0;
}