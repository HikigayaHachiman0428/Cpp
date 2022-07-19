#include <bits/stdc++.h>
using namespace std;
const int MAX = 2 * 1e5 + 1;
// 排列组合每个附件和主件的组合，接着就01背包
int n, m;
int c[61][5], w[61][5];
bool picked[61];
int f[MAX];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int cost, weight, main;
        cin >> cost >> weight >> main;
        if (main != 0)
        {
            int k = 2;
            if (c[main][k] != 0)
                k++;
            c[main][k] = cost + c[main][1];
            w[main][k] = weight * cost + w[main][1];
            if (k == 3)
            {
                c[main][4] = c[main][2] + c[main][3] - c[main][1];
                w[main][4] = w[main][2] + w[main][3] - w[main][1];
            }
        }
        else
        {
            c[i][1] = cost;
            w[i][1] = weight * cost;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (c[i][1] == 0)
            continue;
        for (int j = n; j >= c[i][1]; j--)
        {
            f[j] = max(f[j], f[j - c[i][1]] + w[i][1]);
            if (c[i][2] != 0 && j >= c[i][2])
                f[j] = max(f[j], f[j - c[i][2]] + w[i][2]);
            if (c[i][3] != 0 && j >= c[i][3])
            {
                f[j] = max(f[j], f[j - c[i][3]] + w[i][3]);
                if (j >= c[i][4])
                    f[j] = max(f[j], f[j - c[i][4]] + w[i][4]);
            }
        }
    }
    cout << f[n];
    return 0;
}