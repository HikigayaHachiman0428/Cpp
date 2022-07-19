#include <iostream> #include <cmath> #include<algorithm>
using namespace std;
const int maxn = 1e5+5;
int n,m,k;
int cow[30][maxn], ans[maxn];

int main(){
  cin>>n>>m>>k;
  for (int i =1; i<=n; i++){
    cow[0][i] = i;
    ans[i] = i;
  }
  for (int i =1; i<=m; i++){
    int l, r;
    cin>>l>>r;
    reverse(cow[0]+l,cow[0]+r+1);
  }
  for (int i = 1; (1<<i)<=k; i++)
    for (int j =1; j<=n; j++){
      cow[i][j] = cow[i-1][cow[i-1][j]];
    }
  for (int i = 0; (1<<i)<=k; i++){
    if ((k>>i)&1){
      for (int j = 1; j<=n; j++)
        ans[j] = cow[i][ans[j]];
    }
  }
  for (int i =1; i<=n; i++) cout<<ans[i]<<endl;
}
