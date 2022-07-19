#include <bits/stdc++.h>
using namespace std;
// sort 记顺序, 再对着sort完记录的rank数组使用树状数组存贮比它大的牛的个数

const int MAXN = 1e5 + 10;
int c[MAXN];
int n, q, k, a, b;
long long ans;

int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += v;
}

struct cow
{
    int h;
    int index;
} COW[MAXN];

bool cmp(cow a, cow b)
{
    return a.h > b.h;
}

int getSum(int x)
{
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += c[i];
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int height;
        cin >> height;
        COW[i] = {height, i};
    }
    sort(COW + 1, COW + 1 + n, cmp);
    for (int i =1; i<=n; i++)
    {
        
        int ll = getSum(COW[i].index);
        int rr = i-ll-1;
        update(COW[i].index, 1);
        if (max(ll,rr) > min(ll,rr) * 2){
            // cout <<COW[i].index<<" "<<ll<<" "<<rr<<endl;
            ans++;
        }
    }
    // cout<<endl;
    cout<<ans;
}