#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
const int maxn = 1e5+5;
/*
3
6
1 2 3 1 1 1
3
2 2 3
5
0 0 0 0 0
*/
set<int> factors;

void getFactors(int max, int sum){
  factors.insert(sum);
  if (sum == 0) return;
  while (sum%2 == 0){
      if (2 > max) {
        factors.insert(2);
      }
      sum/=2;
   }
   for (int i = max; i <= sqrt(sum); i = i+2){
    while (sum%i == 0){
      if (i >= max) {
        factors.insert(i);
      }
      sum = sum/i;
    }
   }
}

int main(){
  int t; cin>>t;
  for (int index =1; index<=t ; index++){
    int n; cin>>n;
    int sum = 0, maximum = 0, ans = 1e9; int a[maxn];
    for (int i =1; i<=n; i++){
      int temp; cin>>temp;
      a[i] = temp;
      sum += temp;
      maximum = max(maximum, temp);
    }
    factors.clear();
    getFactors(maximum,sum);
    set<int>::iterator it;
    for(it=factors.begin();it!=factors.end();it++){
      bool flag = true; int step = 0;
      for(int i =1; i<=n; i++){
        if(a[i] == *it) continue;
        int temp = 0;
        while (i<=n && temp<*it){
          temp+=a[i];
          step++;
          i++;
        }
        step--;
        if (temp != *it) {
          flag = false;
          break;
        }
      }
      if (flag) ans = min(ans, step);
    }
    cout<<ans<<endl;
  }
}
