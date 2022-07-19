#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1005];
int f[1005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= a[i]; j--)
            f[j] += f[j-a[i]]; // 对于每一种钱数都加上不吃
    }
    cout << f[m];
}