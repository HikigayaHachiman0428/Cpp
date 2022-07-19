#include <bits/stdc++.h>
#define debug(i) cout << i << " ";
using namespace std;
int n;
int s[101][101], f[101][101], a[101];
void ans()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int s = 1; s < i * 2; s++)
            cout << " ";
        for (int j = i; j <= n; ++j)
            cout << f[j][i] << " ";
        cout << endl;
    }
}

int main()
{
    iostream::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            // cout << a[j] << " " << j - i << " ";
            s[i][j] = s[i][j - 1];
            if (a[j] != j - i)
                s[i][j]++;
            // cout << s[i][j] << " ";
        }
        // cout << endl;
    }
    memset(f, 64, sizeof(f));
    for (int i = 0; i <= n; ++i)
        f[i][0] = 0;
    for (int day = 1; day<= n; ++day)
        for (int escape = 1; escape<=day; ++escape)
            for (int k = day + 1; k<=n; ++k)
            {
                f[day][escape] = min(f[day][escape], f[])
            }
    // ans();
    return 0;
}