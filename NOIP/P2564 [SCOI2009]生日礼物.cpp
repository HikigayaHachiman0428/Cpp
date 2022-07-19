#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int maxn = 1000005;
int n, k;
struct jewel{
  int type;
  int pos;
  bool operator< (const jewel &o) const
  {
    return pos < o.pos;
  }
};

bool cmp(jewel a, jewel b){
  return a.pos<b.pos;
}
vector <jewel> j;

int main(){
  cin>>n>>k;
  for (int i = 1; i<=k; i++){
    int cnt; cin>>cnt;
    for (int index =1; index<=cnt;index++){
      jewel P; cin>>P.pos; P.type = i;
      j.push_back(P);
    }
  }
  int s = j.size();
  sort(j.begin(),j.end());
  for (int i = 0; i<j.size(); i++)
    cout<<j[i].pos<<" "<<j[i].type<<endl;
  cout<<endl;
  int l = 0, r = 0, cnt = 0, ans = 1e9;
  map<int, int> m;
  while (r < n){
    int key = r;
    while (j[r].pos == j[key].pos){
      m[j[r].type]++;
      if (m[j[r].type] == 1) cnt ++;
      r++;
    }
    r--;
    if (cnt >= k){
      ans = min(ans, j[r].pos - j[l].pos + 1); cout<<j[l].pos << " "<< j[r].pos<<endl;
      while (cnt > k){
        int index;
        for (index = l; j[index].pos == j[l].pos; index++){
          if (--m[j[index].type] == 0) cnt --;
        }
        l = index-1;
        if (cnt >= k) {ans = min(ans, j[r-1].pos - j[l].pos + 1); cout<<j[l-1].pos << " "<< j[r-1].pos<<endl;}
      }
    }
  }
  cout<<endl<<ans<<endl;
}
