#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int ans;
int main()
{
    int n;
    cin >> n;
    //顺推
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
            a[i][j] += max(a[i-1][j], a[i - 1][j - 1]);
        }
    for (int i = 1; i <= n; i++)
        ans = max(ans, a[n][i]);
    cout << ans;
}