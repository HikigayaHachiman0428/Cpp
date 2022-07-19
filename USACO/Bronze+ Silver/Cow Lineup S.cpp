#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 50005;
int n;
struct cow{
  int x;
  int id;
}cows[maxn];
bool cmp(cow a, cow b){
  return a.x < b.x;
}

set <int> s;
map <int,int> c;
// 尺取，用set和map查重
int main()
{
  cin>>n;
  for (int i =1; i<=n; i++){
    cin>>cows[i].x>>cows[i].id;
    s.insert(cows[i].id);
  }
  int sum = s.size();
  // cout<<"sum = "<<sum<<endl;
  sort(cows+1, cows+1+n, cmp);
  int l = 1, ans = 1e9, kinds = 0;
  for (int r = 1; r<=n; r++){
    c[cows[r].id]++;
    // cout<<cows[r].id<<" "<<c[cows[r].id]<<endl;
    if (c[cows[r].id] == 1) {
      kinds++;
      // cout<<" kinds ="<<kinds<<endl;
    }
    if (kinds == sum){
      while (kinds == sum){
        c[cows[l].id]--;
        if(c[cows[l].id] == 0) kinds--;
        l++;
      }
      ans = min(ans, cows[r].x - cows[l-1].x);
    }
  }
  cout<<ans<<endl;
}
