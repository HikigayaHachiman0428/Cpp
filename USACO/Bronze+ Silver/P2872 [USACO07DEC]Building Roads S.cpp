#include <bits/stdc++.h>
#define p pair<int, int>
using namespace std;
const int maxn = 1005;
const int maxm = 2 * 100000 + 1;
double getLen(p a, p b)
{
    return (double)(sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2)));
}
struct edge
{
    p x, y;
    int index;
    double w;
} a[maxm];
p point[maxn];
bool connect[maxn][maxn];
int f[maxn];
int n, m, cnt;
double ans;

bool cmp(edge x, edge y)
{
    return x.w < y.w;
}

void init()
{
    for (int i = 0; i <= n; i++)
        f[i] = i;
}

int find(int x)
{
    if (x == f[x])
        return x;
    f[x] = find(f[x]);
    return f[x];
}

void merge(int x, int y, double w)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        f[fy] = fx;
        ans += w;
        cnt++;
    }
}

int main()
{
    cin >> n >> m;
    init();
    // input
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        point[i] = make_pair(x, y);
    }
    sort(point + 1, point + 1 + n);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        connect[x][y] = true;
    }
    int sum = 1;
    for (int i = 1; i <= n - 1; i++)
        for (int j = i + 1; j <= n; i++)
        {
            if (!connect[i][j])
                a[sum] = {point[i], point[j], sum, getLen(point[i], point[j])};
            else
                a[sum] = {point[i], point[j], sum, 0};
            sum++;
        }
    cout << "2" << endl;
    sort(a + 1, a + sum + 1, cmp);
    cout << "3" << endl;
    //便利一遍边，merge
    for (int i = 1; i <= sum; i++)
    {
        merge(a[i].index, a[i].index, a[i].w);
        if (cnt == n - 1)
            break;
    }
    if (cnt == n - 1)
        cout << ans;
    return 0;
}
