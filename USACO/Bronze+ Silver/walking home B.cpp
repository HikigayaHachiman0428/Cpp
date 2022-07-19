#include <iostream>
using namespace std;
int K, N, ans;
bool hay[55][55];
void dfs(int x, int y, int k, char dir){
  if (x>N || y>N || hay[x][y] || k>K)
    return;
  if (x == N && y == N){
    ans++;
    return;
  }
  if (dir == 'r'){
    dfs(x+1, y, k,'r');
    dfs(x, y+1, k+1,'d');
  }
  else{
    dfs(x+1, y, k+1, 'r');
    dfs(x,y+1, k, 'd');
  }
}
int main(){
  int t;
  cin >>t;
  while (t--){
    cin>>N>>K; ans = 0;
    for (int x = 1; x<=N; x++)
      for (int y = 1; y<=N; y++){
        char point; cin>>point;
        if (point == 'H') hay[x][y] = true;
        else hay[x][y] = false;
      }
    dfs(2,1,0,'r');
    dfs(1,2,0,'d');
    cout<<ans<<endl;
  }
}
