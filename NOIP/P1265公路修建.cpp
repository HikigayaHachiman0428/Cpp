#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

const int maxn = 5001;
using namespace std;
struct edge
{
    int x, y;
    double w;
} a[maxn][maxn];

int f[maxn];
int n,m, cnt;
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

struct point
{
    int x, y;
} v[maxn];

double getDist(point a, point b)
{
    return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

int main()
{
    cin >> n;
    init();
    // input
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }
    for (int i = 1; i <= n; i++){
        int index = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i != j){
                index++;
                a[i][index] = {i, j, getDist(v[i], v[j])};
            }
        }
        sort(a[i]+1, a[i]+n, cmp);
    }
    // for (int i = 1; i <= n -1 ; i++)
    //     for (int j =1 ; j<=n; j++)
    //         cout << a[j][i].x <<" "<< a[j][i].y<<" " << a[j][i].w << endl;
    //便利一遍边，merge
    for (int i = 1; i <= n-1; i++)
    {
        for (int j = 1; j<=n; j++){
            merge(a[j][i].x, a[j][i].y, a[j][i].w);
            if (cnt == n - 1)
                break;
        }
    }
    cout << fixed << setprecision(2) << ans;
}
