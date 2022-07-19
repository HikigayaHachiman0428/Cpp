#include <bits/stdc++.h>
using namespace std;
// 因为需要一个一个挪动，所以挪动的总步数为最后一个需要挪动的数的index（即为第一个逆序出现的地方）
// 分为左右两侧，分别统计需要挪动的个数
// 左侧挪动个数为num -1; 右侧用BIT统计比挪过去的数小的个数

const int MAXN = 1e5 + 10;
int c[MAXN];
int cow[MAXN];
int n;

int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += v;
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
        cin >> cow[i];
    int cnt = 0;
    for (int i = n; i >= 1; i--)
    {

        cnt++;
        update(cow[i], 1);
        if (cow[i] < cow[i - 1])
            break;
    }
    cout << n - cnt<<endl;
    for (int i = 1; i <= n - cnt; i++)
    {
        int ans = 0;
        ans += n - cnt - i;
        ans += getSum(cow[i]);
        update(cow[i], 1);
        cout << ans << " ";
    }
    return 0;
}