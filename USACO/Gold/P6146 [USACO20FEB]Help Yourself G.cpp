#include <iostream>
#include <algorithm>
#define p pair<int, int>
const int mod = 1e9 + 7;
using namespace std;
const int maxn = 1e5 + 1;
int n;
long long x[2*maxn];
p s[maxn];
long long f[maxn];
/*
如果我们新添加了一条线段，复杂度会怎样变化呢？
1, 不选这条线段(已经包括在子集中)
这种情况下，复杂度没有变化，不包含这条线段的子集的复杂度仍然为f[i-1]
2, 选这条线段
复杂度分两部分：
原来的复杂度（这部分不会因为新选一条线段而减少，因为线段已经按左端点排好顺序了)
新增加的复杂度（这条线段可能不与已有线段形成连通块）。
如果之前的线段中有x条线段不与当前线段相交,则选这x条线段的一个子集加上当前线段
可以让复杂度在原来子集的复杂度基础上 +1。
根据集合的知识，新增加的复杂度就是2^x
得递推式f[i] = f[i - 1] + （f[i - 1] + 2^x) = 2*f[i-1] + 2^x
*/

long long getKSM(long long a, long long b, long long k)
{
    int ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans = (1LL * ans * a) % k;
        }
        a = (1LL * a * a) % k;
        b /= 2;
    }
    return ans % k;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i].first >> s[i].second;
        ++x[s[i].second];
    }
    sort(s + 1, s + 1 + n);
    for (int i = 1; i <= 2 * n; ++i)
        x[i] += x[i - 1];
    for (int i = 1; i <= n; ++i)
    {
        f[i] = (2 * f[i - 1] + getKSM(2, x[s[i].first - 1], mod)) % mod;
    }
    cout<<f[n];
    return 0;
}