#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int shudu[9][9];
int score[9][9] = {
  {6,6,6,6,6,6,6,6,6},
  {6,7,7,7,7,7,7,7,6},
  {6,7,8,8,8,8,8,7,6},
  {6,7,8,9,9,9,8,7,6},
  {6,7,8,9,10,9,8,7,6},
  {6,7,8,9,9,9,8,7,6},
  {6,7,8,8,8,8,8,7,6},
  {6,7,7,7,7,7,7,7,6},
  {6,6,6,6,6,6,6,6,6}
};
int cnt[9 ];

int main(){
  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
      cin>>shudu[i][j];
      if(shudu[i][j] == 0)
        cnt[j]++;
    }
  }

}
