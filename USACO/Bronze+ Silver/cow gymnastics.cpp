#include <iostream>
using namespace std;
int p[21][21];

int main(){
  int n,k; cin>>k>>n;
  for (int index = 1; index <=k ; index++){
    int temp[21];
    for (int i =1; i<=n; i++){
      cin>>temp[i];
    }
    for (int i = 1; i<=n-1; i++){
      for (int j=i+1; j<=n; j++){
        p[temp[i]][temp[j]]++;
      }
    }
  }
  int ans = 0;
  for (int i =1; i<=n; i++)
    for (int j = 1; j<=n; j++)
      if (p[i][j] == k) {
        ans++;
      }
  cout<<ans<<endl;
}
