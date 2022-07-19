#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace fastIO
{
    template <typename T>
    inline T read()
    {
        T X = 0;
        bool flag = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = 0;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            X = (X << 1) + (X << 3) + ch - '0';
            ch = getchar();
        }
        if (flag)
            return X;
        return ~(X - 1);
    }

    template <typename T>
    inline void printf(T X)
    {
        if (X < 0)
        {
            putchar('-');
            X = ~(X - 1);
        }
        int s[50], top = 0;
        while (X)
        {
            s[++top] = X % 10;
            X /= 10;
        }
        if (!top)
            s[++top] = 0;
        while (top)
            putchar(s[top--] + '0');
        putchar('\n');
        return;
    }
}
using namespace fastIO;

const int N = 1e4 + 1;
const int M = 5 * N;

struct edge
{
    int to, w;
};

int t, c, ts, te;
int rs, re, ci;
int dis[N];
int b, cost[N];

vector<edge> g[N];

struct point
{
    int id;
    int len;
};

struct cmp
{
    bool operator()(const point &a, const point &b)
    {
        return a.len > b.len;
    }
};

bool dij(int MAX)
{
    if (cost[ts] > MAX)
        return false;
    priority_queue<point, vector<point>, cmp> pq;
    bool vis[N];
    fill(dis + 1, dis + 1 + t, LONG_MAX);
    memset(vis, false, sizeof(vis));
    dis[ts] = 0;
    pq.push({ts, 0});
    while (!pq.empty())
    {
        int id = pq.top().id;
        pq.pop();

        if (vis[id])
            continue;
        vis[id] = true;
        // if (cost[id] > MAX)
        //     continue;
        for (edge e : g[id])
        {
            if (dis[e.to] > dis[id] + e.w && cost[e.to] <= MAX)
            {
                dis[e.to] = dis[id] + e.w;
                pq.push({e.to, dis[e.to]});
            }
        }
    }
    // cout << dis[te] << endl;
    if (b - dis[te] < 0)
        return false;
    else
        return true;
}

signed main()
{
    t = read<int>();
    c = read<int>();
    b = read<int>();
    int tempc[N];
    for (int i = 1; i <= t; i++)
    {
        cost[i] = read<int>();
        tempc[i] = cost[i];
    }
    for (int i = 1; i <= c; i++)
    {
        rs = read<int>();
        re = read<int>();
        ci = read<int>();
        g[rs].push_back({re, ci});
        g[re].push_back({rs, ci});
    }
    ts = 1;
    te = t;
    sort(tempc + 1, tempc + 1 + t);
    int ll = 1;
    int rr = t;
    int ans = LONG_MAX;
    while (ll <= rr)
    {
        int mid = (ll + rr) / 2;
        if (dij(tempc[mid]))
        {
            ans = min(ans, tempc[mid]);
            rr = mid - 1;
        }
        else
        {
            ll = mid + 1;
        }
        // cout << ans << endl;
    }
    if (ans < LONG_MAX)
        printf(ans);
    else
        printf("AFK");
    return 0;
}