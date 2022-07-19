#include <iostream>
#include <vector>
#include <algorithm>
#define p pair<int, int>
#define ll long long
using namespace std;
/*
7 5 10 -2 0 3 0 4 0 5 0 0 10 0 -10 0 10
*/
ll n, X,Y;
p dir[45];
ll ans[45];
struct first_half{
  ll x;
  ll y;
  ll num;
};
vector<first_half> f;
bool cmp_first(first_half a, first_half b){
  if (a.x != b.x){
    return a.x<b.x;
  }
  if (a.y != b.y){
    return a.y<b.y;
  }
  return a.num<b.num;
}

struct second_half{
  ll x;
  ll y;
  ll num;
  ll cnt;
  bool operator<(const second_half& o) const
  {
    if (x!=o.x)
      return x <o.x;
    return y<o.y;
  }
};
vector<second_half> s;

void subset_first(int N, int seq) {
    int x=0, y=0, num=0;
    for(int i=0 ; i<N; i++) {
        if( seq & (1<<i) ) {
          num++;
          x+=dir[i+1].first;
          y+=dir[i+1].second;
        }
    }
    first_half Push ={x,y,num};
    f.push_back(Push);
}
second_half subset_second(int N, int seq){
  ll x=0, y=0, num=0;
  for(int i= n/2 + 1; i<=N; i++) {
      if( (seq & (1<<(i-n/2-1))) == (1<<(i-n/2-1))) {
        num++;
        x+=dir[i].first;
        y+=dir[i].second;
      }
  }
  second_half Push ={X-x,Y-y,num,0};
  return Push;
}


bool cmp(second_half a, second_half b){
  if(a.x != b.x) return a.x<b.x;
  return a.y<b.y;
}

void set_up_s(){
  for (int i =1; i<f.size(); i++){
    if(f[i-1].x != f[i].x){
      second_half Push = {f[i].x,f[i].y,f[i].num, 1};
      s.push_back(Push);
    }
    else{
      s[s.size()-1].cnt++;
    }
  }
}

int main(){
  cin>>n>>X>>Y;
  for (int i =1; i<=n; i++){
    cin>>dir[i].first>>dir[i].second;
  }
  for(int i=0; i<(1<<n/2); i++) {
      subset_first(n/2, i);
  }
  sort(f.begin(),f.end(),cmp_first);
  // cout<<f.size()<<endl;
  // for (int i = 0; i< f.size(); i++){
  //   cout<<f[i].x<<" "<<f[i].y<<" "<<f[i].num<<endl;
  // }
  second_half one;
  one.x = f[0].x; one.y = f[0].y; one.num = f[0].num; one.cnt = 1;
  s.push_back(one);
  set_up_s();
  for (int i = 0; i < (1<<(n-n/2)); i++){
    second_half a = subset_second(n, i);
    int cnt = a.num; a.num = 0;
   // cout<<a.x<<" "<<a.y<<" "<<a.num<<" "<<a.cnt<<endl;
    int pos = lower_bound(s.begin(),s.end(),a) - s.begin();
    while(!(a < s[pos])&& pos < s.size()){
      ans[cnt+s[pos].num] += s[pos].cnt;
      pos++;
    }
  }
  for (ll i = 1; i<=n; i++){
    cout<<ans[i]<<endl;
  }
}
