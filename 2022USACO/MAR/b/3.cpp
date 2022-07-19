#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, k, ori;
// 要求最大值，不断的把第N个数加一，然后check, 直到不行为止
/*
5
2 0 0 1 0
3
5 2 3 4
2 1 1
3 1 2
*/
long long val[maxn * maxn];
long long cashe[maxn * maxn];
vector<long long> req[maxn];

bool check(long long in[])
{
    long long temp[maxn];
    for (int i = 1; i <= n; i++)
    {
        temp[i] = in[i];
        // cout<<temp[i]<<" ";
    }
    // cout << endl;
    for (int i = n; i >= 1; i--)
    {
        // cout << i << endl;
        if (temp[i] > cashe[i])
        {
            if (req[i].empty())
                return false;
            for (int j = 0; j < req[i].size(); j++)
            {
                int need = req[i][j];
                temp[need] += temp[i] - cashe[i];
            }   
        }
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cashe[i];
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int cur;
        cin >> cur;
        int cnt;
        cin >> cnt;
        for (int j = 1; j <= cnt; j++)
        {
            int temp;
            cin >> temp;
            req[cur].push_back(temp);
        }
    }
    while (true)
    {
        val[n]++;
        if (!check(val))
        {
            cout << val[n] - 1;
            break;
        }
    }
}