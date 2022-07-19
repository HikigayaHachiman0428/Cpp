#include <bits/stdc++.h>
using namespace std;
struct trash
{
    int t, f, h;
} t[105];
int f[105]; // 在i高度下卡门的最大生命值

bool cmp(trash a, trash b)
{
    return a.t < b.t;
}

int d, g;
int main()
{
    cin >> d >> g;
    for (int i = 1; i <= g; i++)
        cin >> t[i].t >> t[i].f >> t[i].h;
    sort(t + 1, t + 1 + g, cmp);
    f[0] = 10;
    for (int i = 1; i <= g; i++)
    {
        for (int j = d; j >= 0; j--)
        {
            f[j] = max(f[j + t[i].h], f[j]);
            f[j] += t[i].f;
        }
    }
    cout<<f[0];
    return 0;
}