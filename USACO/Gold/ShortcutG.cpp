#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
// 先dij, 删除多余路径, 处理出一个树,dfs算每个点通过的牛, 再o(n)遍历处理

const int N = 10005;
const int M = 50001;

struct edge
{
    int to, w;
};

int n, m,t;
int c[N];
ll dis[N];
ll cnt[N];
int par[N];
bool vis[N];
ll ans;

vector<edge> g[N];
vector<int> prog[N];

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

priority_queue<point, vector<point>, cmp> pq;

void dij()
{
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    pq.push({1, 0});

    while (!pq.empty())
    {
        int id = pq.top().id;
        pq.pop();

        if (vis[id])
            continue;
        vis[id] = true;

        for (edge e : g[id])
        {
            if (dis[e.to] > dis[id] + e.w)
            {
                dis[e.to] = dis[id] + e.w;
                point p = {e.to, dis[e.to]};
                pq.push(p);
                par[e.to] = id;
            }
            else if(dis[e.to] == dis[id] + e.w){
                if(par[e.to] > id){
                    par[e.to] = id; 
                }
            }
        }
    }
}

void dfs(int cur, int par){
    int sum = c[cur];
    for (int i = 0; i<prog[cur].size();i++){
        if (prog[cur][i] == par) continue;
        dfs(prog[cur][i],cur);
        sum+= cnt[prog[cur][i]];
    }
    cnt[cur] = sum;
}

int main()
{
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++)
    {
        int rs, re, ci;
        cin >> rs >> re >> ci;
        g[rs].push_back({re, ci});
        g[re].push_back({rs, ci});
    }
    dij();
    for (int i = 2; i <= n; i++)
    {
        prog[i].push_back(par[i]);
        prog[par[i]].push_back(i);
    }
    dfs(1,-1);
    for (int i = 1; i<=n; i++){
        ans = max(ans, cnt[i]* (dis[i] - t));
    }
    cout<<ans;
}
