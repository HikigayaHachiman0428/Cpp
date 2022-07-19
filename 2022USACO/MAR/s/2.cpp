#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
string first, second;
int q;
bool check[29][29];
/*
aabcd
caabd
4
a
ac
abd
abcd
*/

int main()
{
    cin >> first >> second;
    for (int i = 0; i < 18; i++)
        for (int j = i; j < 18; j++)
        {
            string t1 = "";
            string t2 = "";
            for (int k = 0; k < first.length(); k++)
                if ((first[k] == i + 'a') || (first[k] == 'a' + j))
                {
                    t1 += first[k];
                }
            for (int k = 0; k < second.length(); k++)
                if ((second[k] == i + 'a') || (second[k] == j + 'a'))
                {
                    t2 += second[k];
                }
            // cout<<t1<<" "<<t2<<endl;
            if (t1.length() != t2.length())
            {
                check[i][j] = false;
                continue;
            }
            check[i][j] = (t1 == t2);
        }
    // for (int i = 0; i<18; i++)
    //     for (int j =0; j<18; j++){
    //         cout<<check[i][j]<<endl;
    //     }
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        bool flag = true;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                int a = (int)s[i] - 97;
                int b = (int)s[j] - 97;
                if (!check[a][b])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
        if (flag)
            cout << "Y";
        else
            cout << "N";
    }
}