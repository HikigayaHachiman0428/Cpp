#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 5;
string s;
int q;
int prefixc[maxn];
int prefixo[maxn];
int prefixw[maxn];

/*
COW
6
1 1
1 2
1 3
2 2
2 3
3 3
*/

int main()
{
    cin >> s;
    for (int i = 1; i <= s.size(); i++)
    {
        if (s[i - 1] == 'C')
            prefixc[i]++;
        else if (s[i - 1] == 'O')
            prefixo[i]++;
        else
            prefixw[i]++;
        prefixc[i] += prefixc[i - 1];
        prefixo[i] += prefixo[i - 1];
        prefixw[i] += prefixw[i - 1];
    }
    cin >> q;
    string ans = "";
    for (int index = 1; index <= q; index++)
    {
        int ll, rr;
        cin >> ll >> rr;
        int c = prefixc[rr] - prefixc[ll - 1];
        // cout << c << " ";
        int o = prefixo[rr] - prefixo[ll - 1];
        // cout << o << " ";
        int w = prefixw[rr] - prefixw[ll - 1];
        // cout << w << endl;
        if (c % 2 == 0)
        {
            if (o % 2 == 1 && w % 2 == 1)
                ans += "Y";
            else
                ans += "N";
        }
        else
        {
            if (o % 2 == 0 && w % 2 == 0)
                ans += "Y";
            else
                ans += "N";
        }
    }
    cout << ans << endl;
}