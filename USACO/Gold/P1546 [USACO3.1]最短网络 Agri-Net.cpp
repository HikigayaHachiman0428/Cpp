#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip> 

const int maxn = 501;
const int maxm = maxn * maxn;
using namespace std;
struct edge
{
    int x, y;
    double w;
} a[maxm];

int f[maxn];
int n, m, s, cnt;
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
        ans = max(ans , w);
        cnt++;
    }
}

struct point
{
    int x, y;
} v[maxn];

double getDist(point a, point b)
{
    return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

signed main()
{
    cin >> s >> n;
    init();
    // input
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
        {
            m++;
            a[m] = {i, j, getDist(v[i], v[j])};
        }
    sort(a + 1, a + m + 1, cmp);
    // for (int i = 1; i <= m; i++)
    // {
    //     cout << a[i].x <<" "<< a[i].y<<" " << a[i].w << endl;
    // }
    //便利一遍边，merge
    for (int i = 1; i <= m; i++)
    {
        merge(a[i].x, a[i].y, a[i].w);
        if (cnt == n - s)
            break;
    }
	cout<<fixed << setprecision(2) <<ans;
}
