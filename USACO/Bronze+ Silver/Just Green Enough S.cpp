#include <bits/stdc++.h>
using namespace std;
int pasture[510][510], colmin[510];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &pasture[i][j]);
        }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            int left = 0, cnt = 0;
            for (int k = 1; k <= n; k++) {
                // TODO
            }
        }

    cout << ans << endl;
    return 0;
}