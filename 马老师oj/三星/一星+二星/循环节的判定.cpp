#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, a;
    cin >> s >> a;
    if (s.length() < a.length())
    {
        string temp = s;
        s = a;
        a = temp;
    }
    if (s.length() % a.length() != 0)
    {
        cout << "No";
        return 0;
    }
    for (int i = 0; i < s.length(); i += a.length())
    {
        if (s.substr(i, i + a.length()) != a)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}