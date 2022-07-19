#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;
const int M = 2 * N;

struct edge
{
    int to, w;
};

int t, c, ts, te;
int rs, re, ci, MAX;
int dis[N], len[N];

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

bool dij()
{
    priority_queue<point, vector<point>, cmp> pq;
    bool vis[N];
    memset(dis, 0x3f, sizeof(dis));
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

        for (edge e : g[id])
        {
            if (dis[e.to] > dis[id] + e.w && e.w <= MAX)
            {
                dis[e.to] = dis[id] + e.w;
                pq.push({e.to, dis[e.to]});
            }
        }
    }
    if (dis[te] < 1e9)
        return true;
    else
        return false;
}

signed main()
{
    cin >> t >> c >> ts >> te;
    for (int i = 0; i < c; i++)
    {
        cin >> rs >> re >> ci;
        g[rs].push_back({re, ci});
        g[re].push_back({rs, ci});
        len[i] = ci;
    }
    sort(len, len + c);
    int ll = 0;
    int rr = c;
    int ans;
    while (ll <= rr)
    {
        int mid = (ll + rr) / 2;
        MAX = len[mid];
        if (dij())
        {
            ans = mid;
            rr = mid - 1;
        }
        else
        {
            ll = mid + 1;
        }
    }
    cout << len[ans];
    return 0;
}
