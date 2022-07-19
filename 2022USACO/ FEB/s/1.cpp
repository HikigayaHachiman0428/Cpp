#include <iostream>
using namespace std;
const int maxn = 505;
bool change[maxn][maxn]; // 用 i 换 j
int prefer[maxn][maxn];
int n;
/*
4 1 2 3 4 1 3 2 4 1 2 3 4 1 2 3 4
*/

void set_up_exchange(){
  for (int i = 1; i<=n; i++){
    for (int j = 1; j<=n; j++){
      change[prefer[i][j]][i] = 1;
      if (prefer[i][j] == i) break;
    }
  }
}

void chk(int i, int j, int mid){
  if (change[i][mid] == true && change[mid][j] == true)
    change[i][j] = true;
}

int main(){
  cin>>n;
  for (int i =1; i<=n; i++){
    for (int j =1; j<=n; j++){
      cin>>prefer[i][j];
    }
  }
  set_up_exchange();
  int mid =1;
  while(mid<=n){
    for (int i = 1; i<=n; i++)
      for (int j = 1; j<=n; j++){
        chk(i,j,mid);
      }
    mid++;
  }
  for (int i =1; i<= n; i++)
    for (int j =1;j<=n; j++){
      if (change[i][prefer[i][j]]){
        cout<<prefer[i][j]<<endl;
        break;
      }
    }
}
