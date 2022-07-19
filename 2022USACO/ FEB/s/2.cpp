#include <iostream>
#include <algorithm>
#include <cstring>
#define p pair<int, int>
using namespace std;
/*
7 5 10 -2 0 3 0 4 0 5 0 0 10 0 -10 0 10
*/
int n, X,Y;
int ans[45];

struct zuhe{
  p pos;
  int num;
} First[25], Second[25],first_set[500],second_set[500];

int fir_pointer, sec_pointer;

void subset_first(int N, int seq,int index) {
    int x=0, y=0, num=0;
    for(int i=0 ; i<N; i++) {
        if( seq & (1<<i) ) {
          x+=First[i].pos.first;
          y+=First[i].pos.second;
          num+=First[i].num;
        }
    }
    first_set[index].pos.first = x; first_set[index].pos.second = y; first_set[index].num = num;
}
void subset_second(int N, int seq,int index){
    int x=0, y=0, num=0;
    for(int i=0; i<N; i++) {
        if( seq & (1<<i) ) {
             x+=Second[i].pos.first;
             y+=Second[i].pos.second;
             num+=Second[i].num;
        }
    }
    second_set[index].pos.first = x; second_set[index].pos.second = y; second_set[index].num = num;
}
bool cmp(zuhe const& a, zuhe const& b){
  if (a.pos.first != b.pos.first)
    return a.pos.first < b.pos.first;
  else
    return a.pos.second < b.pos.second;
}

bool chk(zuhe a, zuhe b){
  // cout<<a.pos.first<<" "<< a.pos.second<<" "<< b.pos.first<<" "<< b.pos.second;
  if (a.pos.first + b.pos.first == X && a.pos.second + b.pos.second ==Y){
    ans[a.num+b.num]++;
    // cout<<" "<<a.num+b.num<<endl;
    return true;
  }
  // cout<<endl;
  return false;
}

void print(){
  for (int i = 0; i<fir_pointer; i++){
    cout<<"first["<<i<<"].x = "<<first_set[i].pos.first<<"; y ="<<first_set[i].pos.second<<" num = "<<first_set[i].num<<endl;
  }
  for (int i = 0; i<sec_pointer; i++){
    cout<<"second["<<i<<"].x = "<<second_set[i].pos.first<<"; y ="<<second_set[i].pos.second<<" num = "<<second_set[i].num<<endl;
  }
}


int main(){
    cin>>n>>X>>Y;
    memset(First,0,sizeof(First));
    memset(Second, 0, sizeof(Second));
    for (int i = 0; i< n/2; i++){
      cin>>First[i].pos.first>>First[i].pos.second;
      First[i].num = 1;
    }
    fir_pointer = 1;
    for (int i = 0; i<(n-n/2); i++){
      cin>>Second[i].pos.first>>Second[i].pos.second;
      Second[i].num = 1;
    }
    sec_pointer = 1;
    for(int i=1; i<(1<<n/2); i++) {
        subset_first(n/2, i,fir_pointer++);
    }
    for(int i=1; i<(1<<(n-n/2)); i++) {
        subset_second(n-n/2, i,sec_pointer++);
    }
    sort(first_set,first_set + fir_pointer, &cmp);
    sort(second_set,second_set + sec_pointer, &cmp);
    // print();
    for (int index = 0; index<fir_pointer; index++){
      // cout<<first_set[index].pos.first<<" "<<first_set[index].pos.second<<endl;
      int ll = 0; int rr = sec_pointer-1;
      while (ll<=rr){
        int mid = (ll+rr)/2;
        if (chk(first_set[index],second_set[mid])){
          for (int i =mid + 1; second_set[i].pos.first == second_set[mid].pos.first; i++){
            if (!(chk(first_set[index],second_set[i]))) break;
          }
          break;
        }
        else if (first_set[index].pos.first + second_set[mid].pos.first > X){
          rr = mid -1;
        }
        else if (first_set[index].pos.first + second_set[mid].pos.first == X){
          if (first_set[index].pos.second + second_set[mid].pos.second < Y){
            for (int i =mid + 1; second_set[i].pos.first == second_set[mid].pos.first; i++){
              chk(first_set[index],second_set[i]);
            }
            break;
          }
          else{
            for (int i =mid - 1; second_set[i].pos.first == second_set[mid].pos.first; i--){
              chk(first_set[index],second_set[i]);
            }
            break;
          }
        }
        else{
          ll = mid + 1;
        }
      }
    }
    for (int i = 1; i<=n; i++){
      cout<<ans[i]<<endl;
    }
}
