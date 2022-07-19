#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int steps[105];
    steps[1] = 1;
    steps[2] = 2;
    for (int i = 3; i <= n; i++)
        steps[i] = steps[i - 1] + steps[i - 2];
    cout << steps[n] << endl;
}