#include <iostream>
using namespace std;
int record[14];
bool visited[14];
bool r[20], l[20]; // r 为从左上到右下的对角线， l为右上到左下的对角线
int ans, n;
void print(){
  ans ++;
  if (ans<4){
    for(int i =1;i<=n; i++){
      cout<<record[i]<<" ";
    }
    cout<<endl;
  }
}

void queen(int row){
  if (row > n){
    print();
    return;
  }
  for (int column = 1; column<=n; column++){
    if (!visited[column] && !r[row-column+6] && !l[row+column]){
      record[row] = column;
      visited[column] = true;
      r[row-column+6] = true;
      l[row+column] = true;
      queen(row+1);
      visited[column] = false;
      r[row-column+6] = false;
      l[row+column] = false;
    }
  }
}


int main(){
  cin>>n;
  queen(1);
  std::cout << ans << '\n';
}
