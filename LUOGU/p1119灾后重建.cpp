#include <bits/stdc++.h>
using namespace std;
// 复杂度收到给的边的顺序影响
const int N = 205;
const int M = 5001;
int n, m, t[N];
int f[N][N];
int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> t[i];
  n++;
  memset(f, 0x3f, sizeof(f));
  for (int i = 1; i <= m; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    f[a + 1][b + 1] = w;
    f[b + 1][a + 1] = w;
  }
  for (int i = 1; i <= n; i++)
    f[i][i] = 0;
  int q;
  cin >> q;
  int k = 1;
  while (q--)
  {
    int start, end, time;
    cin >> start >> end >> time;
    if (t[start+1] > time || t[end+1] > time)
    {
      cout<<-1<<endl;
      continue;
    }
    for (; t[k] <= time && k<=n; k++)
      for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
        {
            f[x][y] = min(f[x][y], f[x][k] + f[k][y]);
        }
    // for (int i = 1; i <= n; i++)
    // {
    //   for (int j = 1; j <= n; j++)
    //   {
    //     if (f[i][j] > 1e9)
    //       cout << -1 << " ";
    //     else
    //       cout << f[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    if (f[start + 1][end + 1] >= 1e9)
      cout << "-1" << endl;
    else
      cout << f[start + 1][end + 1] << endl;
  }
  return 0;
}