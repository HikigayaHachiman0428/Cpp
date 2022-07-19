#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> task[10001];
int f[10005], busy[10005];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int s, t;
        cin >> s >> t;
        task[s].push_back(t);
        busy[s] = true;
    }
    for (int i = n; i >= 1; i--)
    {
        if (!busy[i])
            f[i] = f[i + 1] + 1;
        else
        {
            for (int t : task[i])
            {
                f[i] = max(f[i], f[i + t]);
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    //     cout << f[i] << " ";
    // cout << endl;
    cout << f[1];
    return 0;
}
