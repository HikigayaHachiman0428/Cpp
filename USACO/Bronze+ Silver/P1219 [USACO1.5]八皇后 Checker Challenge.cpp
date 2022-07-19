#include <bits/stdc++.h>
using namespace std;
int tot, n;
int put[30];
bool row[30], ll[30], rr[30];
void queen(int line)
{
    if (line > n)
    {
        tot++;
        if (tot <= 3)
        {
            for (int i = 1; i <= n; i++)
                cout << put[i] << " ";
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!row[i] && !ll[line - i + n] && !rr[i + line])
        {
            row[i] = true;
            ll[line - i + n] = true;
            rr[i + line] = true;
            put[line] = i;
            queen(line + 1);
            row[i] = false;
            ll[line - i + n] = false;
            rr[i + line] = false;
        }
    }
    return;
}

int main()
{
    cin >> n;
    queen(1);
    cout << tot;
    return 0;
}