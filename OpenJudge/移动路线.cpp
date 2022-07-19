#include <bits/stdc++.h>
using namespace std;
int cashe[22][22];
int main()
{
    int m, n;
    cin >> m >> n;
    cashe[1][1] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                continue;
            cashe[i][j] = cashe[i - 1][j] + cashe[i][j - 1];
        }
    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         cout << cashe[i][j] << " ";
    //     cout << endl;
    // }
    cout << cashe[m][n];
}