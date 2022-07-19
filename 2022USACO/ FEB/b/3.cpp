#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
6 MOOOOO OOOOOO ABCDEF UVWXYZ COW MOO ZOO MOVE CODE FARM
*/
bool exist[5][30];
int zuhe[10];
void init(){
  for (int i = 0; i<=9; i++){
    zuhe[i] = i;
  }
}

bool check(string s){
  while(1){
    bool yes = true;
    for(int i = 0; i<s.length(); i++){
      // cout<<zuhe[i+1]<<" "<<endl;
      if(!exist[zuhe[i]][(int)s[i] - 64]){
        yes = false;
      }
    }
    if(yes) return true;
    if(!next_permutation(zuhe,zuhe+4)) break;
  }
  return false;
}

int main(){
  int n;
  cin>>n;
  for (int index =0; index<4; index++){
    string s; cin>>s;
    for (int i=0; i<6; i++){
      exist[index][(int)s[i] - 64] = true;
    }
  }
  for (int index = 1; index <=n; index ++){
      string s; cin>>s;
      init();
      if (check(s))
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
  }
}
