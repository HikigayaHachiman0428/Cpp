#include <bits/stdc++.h>
using namespace std;
int m, K;
int p[501], f[501][501];

void print(int r)
{
    if (r <= 0)
        return;
    int i;
    for (i = r; i >= 1 && p[r] - p[i - 1] <= f[m][K]; --i)
    {
    }
    print(i);
    cout << i + 1 << " " << r << endl;
}

//区间dp
int main()
{
    iostream::sync_with_stdio(false);
    cin >> m >> K;
    K--;
    memset(f, 64, sizeof(f));
    for (int i = 1; i <= m; ++i)
    {
        cin >> p[i];
        p[i] += p[i - 1];
        f[i][0] = p[i];
    }
    for (int k = 1; k <= K; ++k)
        for (int i = 1; i <= m; ++i)
        {
            for (int j = i - 1; j >= 1; --j)
            {
                // cout << j << ": " << f[j][k - 1] << " " << i << ": " << p[i] - p[j];
                f[i][k] = min(max(f[j][k - 1], p[i] - p[j]), f[i][k]);
                // cout << " " << f[i][k] << endl;
            }
        }
    print(m);
    return 0;
}