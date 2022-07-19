#include <iostream>
using namespace std;
int M, N, T;
int c[21], f[21][21];
int main()
{
    cin >> N >> T >> M;
    for (int i = 1; i <= N; ++i)
        cin >> c[i];
    for (int i = 1; i <= N; ++i)
        for (int m = M; m >= 1; --m)
            for (int j = T; j >= c[i]; --j)
            {
                f[m][j] = max(f[m][j], max(f[m - 1][T] + 1, f[m][j - c[i]] + 1));
            }
    cout << f[M][T];
    return 0;
}
