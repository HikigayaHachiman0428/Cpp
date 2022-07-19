#include <iostream>
#include <map>
using namespace std;
const int maxn = 1e5+5;
int cows[maxn];
map<int,int> num;

int main() {
    int n, k, ans = 0;
    cin>>n>>k;
    for (int i = 1; i <= n; i++) {
        cin>>cows[i];
    }
    int j =1, kind = 0;
    for (int i = 1; i <= n; i++) {
      num[cows[i]]++;
      if (num[cows[i]] == 1) kind++;
      while (kind == k+2)
      {
        num[cows[j]]--;
        if (num[cows[j]] == 0) kind--;
        j++;
      }
      ans = max(ans, num[cows[i]]);
    }
    cout<< ans;
    return 0;
}
