#include <bits/stdc++.h>
#define p pair<int, int>
using namespace std;
// bessie位置从最左边往右枚举计算,一开始初始值为所有L类型的数量
// maxx=max(maxx, cnt); ans = n - maxx;
const int maxn = 1005;
p cow[maxn];
/*
2
G 3
L 5
*/
int n;
bool cmp(p a, p b){
    if (a.first != b.first)
        return a.first<b.first;
    else
        return a.second>b.second;
}
int main()
{
    cin >> n;
    int maxT = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        char dir;
        cin >> dir;
        int temp;
        cin >> temp;
        if (dir == 'G')
        {
            cow[i] = make_pair(temp, 1);
        }
        else
        {
            cow[i] = make_pair(temp, 0);
            cnt++;
        }
    }
    sort(cow + 1, cow + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        if (cow[i].second == 1)
        {
            cnt++;
            maxT = max(cnt, maxT);
        }
        else
            cnt--;
    }
    cout << n - maxT;
}