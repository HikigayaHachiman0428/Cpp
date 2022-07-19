#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30001;
int fa[MAXN], len[MAXN], pre[MAXN];
void init()
{
    for (int i = 0; i <= MAXN; i++)
    {
        fa[i] = i;
        len[i] = 1;
    }
}

int find(int x)
{
    // 寻找x的祖先
    if (fa[x] == x)
        return x;
    else
        return find(fa[x]);
}
void incre(int x, int p)
{
    while (fa[x] != x)
    {
    }
}

void unite(int x, int y)
{
    y = find(y);
    x = find(x);
    len[y] += len[x];
    fa[x] = y;
}
int main()
{
    int t;
    cin >> t;
    init();
    while (t--)
    {
        char command;
        int i, j;
        cin >> command >> i >> j;
        if (command == 'M')
        {
            unite(i, j);
        }
        else
        {
            if (find(i) != find(j))
                cout << -1 << "\n";
            else
            {
            }
        }
    }
    return 0;
}