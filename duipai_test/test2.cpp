//algorithm
#include <bits/stdc++.h>
using namespace std;

const int N = 205;
// const int M = N * (N - 1) / 2;
int t[N], dis[N];
bool vis[N];
struct edge
{
  int to, w;
};
vector<edge> g[N];

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

int main()
{
    int n, m;
    // freopen("test.in"  ,"r",stdin);
    // freopen("test2.out","w",stdout);
    n = read<int>();
    m = read<int>();
    for (int i = 0; i < n; i++)
    {
        t[i] = read<int>();
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        x = read<int>();
        y = read<int>();
        w = read<int>();
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
    int q = read<int>();
    while(q--)
    {
        int start = read<int>();
        int end = read<int>();
        int min = read<int>();
        memset(dis, 0x3f, sizeof(dis));
        if (t[start] <= min)
        {
        dis[start] = 0;
        memset(vis, false, sizeof(vis));
        for (int k = 1; k <= n; k++)
        {
            int index = 0;
            int MIN = 1e9;
            for (int i = 0; i < n; i++)
            {
            if (dis[i] < MIN)
            {
                if (!vis[i] && t[i] <= min)
                {
                index = i;
                MIN = dis[i];
                }
            }
            }
            vis[index] = true;
            // cout<<index<<" "<<dis[index]<<endl;
            for (edge e : g[index])
            {
            if (dis[e.to] > dis[index] + e.w)
                dis[e.to] = dis[index] + e.w;
            }
        }
        }
        if (dis[end] < 1e9)
        printf(dis[end]);
        else
        printf(-1);
    }
}