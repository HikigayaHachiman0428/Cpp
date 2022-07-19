#include <bits/stdc++.h>
using namespace std;
int n, m, k;
struct edge
{
    int x, y, l;
    bool operator<(const edge a) &
    {
        return l < a.l;
    }
};
vector<edge> cloud;

int fa[1005];
void init()
{
    for (int i = 0; i <= n; i++)
        fa[i] = i;
}

int find(int x)
{
    // 寻找x的祖先
    if (fa[x] == x)
        return x;
    else
        return find(fa[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    fa[x] = y;
}

int main()
{
    cin >> n >> m >> k;
    long long sum = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, y, l;
        cin >> x >> y >> l;
        cloud.push_back({x, y, l});
        sum += l;
    }
    sort(cloud.begin(), cloud.end());
    long long ans = 0;
    if (n - k > cloud.size())
        cout << "No Answer";
    else
    {
        init();
        int connect = 0;
        for (edge i : cloud)
        {
            if (find(i.x) != find(i.y))
            {
                // cout << " " << i.x << " " << i.y << " " <<i.l << endl;
                ans += i.l;
                unite(i.x, i.y);
                connect++;
            }
            if (connect == n - k)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}