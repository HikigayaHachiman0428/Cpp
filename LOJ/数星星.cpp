#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e5 + 10;
ll c[MAXN];
int cnt[MAXN];
int n, q;

int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += v;
}

ll getSum(int x)
{
    ll ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += c[i];
    return ans;
}

int main()
{
    n = 32002;
    cin >> q;
    int key = q;
    while (key--)
    {
        int x, y;
        cin >> x >> y;
        x++;
        // cout<<getSum(x)<<endl;
        cnt[getSum(x)]++;
        update(x, 1);
    }
    for (int i = 0; i < q; i++)
        cout << cnt[i] << endl;
}
