#include <bits/stdc++.h>
using namespace std;
bool vis[100005];
int main()
{
    int n;
    cin >> n;
    int top;
    cin >> top;
    vis[top] = true;
    for (int i = 1; i < n; i++)
    {
        // cout << top << endl;
        int cur;
        cin >> cur;
        if (cur > top)
        {
            vis[cur] = true;
            while (vis[cur - 1])
                cur--;
            top = cur;
        }
        else
        {
            if (cur == top - 1)
            {
                vis[cur] = true;
                top = cur;
            }
            else
            {
                cout << "Invalid";
                return 0;
            }
        }
    }
    cout << "Valid";
    return 0;
}