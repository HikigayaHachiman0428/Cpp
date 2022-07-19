#include <bits/stdc++.h>
using namespace std;
int n;
struct cla
{
    double num;
    int a;
    int b;
    int c;
    int d;
    int index;
} c[10005];

bool cmp1(cla a, cla b)
{
    if (a.a / a.num != b.a / b.num)
        return a.a / a.num > b.a / b.num;
    if (a.b / a.num != b.b / b.num)
        return a.b / a.num > b.b / b.num;
    if (a.c / a.num != b.c / b.num)
        return a.c / a.num > b.c / b.num;
    if (a.d / a.num != b.d / b.num)
        return a.d / a.num > b.d / b.num;
    if (a.num != b.num)
        return a.num > b.num;
    return a.index < b.index;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.length(); j++)
        {
            if (temp[j] == 'A')
                c[i].a++;
            else if (temp[j] == 'B')
                c[i].b++;
            else if (temp[j] == 'C')
                c[i].c++;
            else
                c[i].d++;
        }
        c[i].num = temp.length();
        c[i].index = i;
    }
    sort(c + 1, c + 1 + n, cmp1);
    for (int i = 1; i <= n; i++)
    {
        cout << c[i].index << " ";
    }
}