#include <bits/stdc++.h>
#define ll long long
using namespace std;
queue<int> ans;
const int MAXN = 50005;
ll l[MAXN], r[MAXN];
int n, q;

int lowbit(int x)
{
    return x & (-x);
}

void update(ll arr[], int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        arr[i] += v;
}

ll getSum(ll arr[], int x)
{
    ll ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += arr[i];
    return ans;
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        int k, lh, rh;
        cin >> k >> lh >> rh;
        if (k == 1)
        {
            update(l, lh, 1);
            update(r, rh, 1);
        }
        else
        {
            cout<<getSum(l, rh + 1) - getSum(r, lh - 1)<<endl;
        }
    }
   return 0;
}
