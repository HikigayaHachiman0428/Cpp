// brute
#include <bits/stdc++.h>
using namespace std;

const int N = 205;
const int M = N * (N - 1) / 2;

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
inline void write_endl(T X)
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

struct edge
{
  int to, w;
};

int t, c, ts, te;
int rs, re, ci;
int dis[N], MIN, T[N];

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

void dij()
{
  priority_queue<point, vector<point>, cmp> pq;
  bool vis[N];
  memset(vis, false, sizeof(vis));
  memset(dis, 0x3f, sizeof(dis));
  if (T[ts] <= MIN)
  {
    dis[ts] = 0;
    pq.push({ts, 0});
    while (!pq.empty())
    {
      int id = pq.top().id;
      pq.pop();
      // cout << "vis = "<< vis[id] << endl;
      if (vis[id])
        continue;
      vis[id] = true;

      for (edge e : g[id])
      { 
        if (dis[e.to] > dis[id] + e.w && T[e.to] <= MIN)
        {
          dis[e.to] = dis[id] + e.w;
          pq.push({e.to, dis[e.to]});
        }
      }
    }
  }
}

signed main()
{
    freopen("test.in"  ,"r",stdin);
    freopen("test1.out","w",stdout);
    t = read<int>(); 
    c = read<int>();
    for (int i = 0; i < t; i++)
        T[i] = read<int>();
    for (int i = 0; i < c; i++)
    {
        rs = read<int>();
        re = read<int>();
        ci = read<int>();
        g[rs].push_back({re, ci});
        g[re].push_back({rs, ci});
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        ts = read<int>();
        te = read<int>(); 
        MIN = read<int>();
        dij();
        if (dis[te] < 1e9)
        write_endl(dis[te]);
        else
        write_endl(-1);
    }
    return 0;
}