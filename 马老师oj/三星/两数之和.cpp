#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int num[maxn];
map<long long, bool> vis;
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        vis[num[i]] = true;
    }
    long long target;
    cin >> target;
    for (int i = 1; i <= n && num[i] < target; i++)
    {
        if (vis[target - num[i]] && num[i] != target / 2)
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}