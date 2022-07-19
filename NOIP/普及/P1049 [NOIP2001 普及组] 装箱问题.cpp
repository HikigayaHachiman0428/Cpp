#include <bits/stdc++.h>
using namespace std;
int V, n;
int c[35], f[20005];
int main()
{
    cin >> V >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    // for (int i = 1; i <= V; i++)
    //     cout << f[i] << " ";
    for (int i = 1; i <= n; i++)
        for (int j = V; j >= c[i]; j--)
            f[j] = max(f[j], f[j - c[i]] + c[i]);
    // for (int i = 1; i <= V; i++)
    //     cout << f[i] << " ";
    cout << V - f[V];
}