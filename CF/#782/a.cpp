#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
    cin >> t;
    while (t--)
    {
        int n, r, b;
        cin >> n >> r >> b;
        int keyb = b;
        for (int i = 1; i <= keyb; i++)
        {
            for (int j = 1; j <= r / (b + 1); j++)
                cout << "R";
            r -= r / (b + 1);
            b--;
            cout << "B";
        }
        for (int i = 1; i <= r; i++)
            cout << "R";
        cout << endl;
    }
}