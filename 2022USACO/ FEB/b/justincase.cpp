#include <iostream>
using namespace std;
const int maxn = 100001;
int a[maxn];
int n;
int prefix[maxn];
int getsum(){
  int ret = 0;
  for (int i = 1; i<=n; i++)
    prefix[i]+=prefix[i-1];
  return prefix[n];
}

// 3 6 1 2 3 1 1 1 3 2 2 3 5 0 0 0 0 0
int main(){
  int t;
  cin>>t;
  for(int p = 0; p<t; p++){
    cin>>n;
    for (int i =1; i<=n; i++){
      cin>>a[i];
      prefix[i] = a[i];
    }
    getsum();
    int index = n;
    while (index>=1){
      if (prefix[n] % index != 0){
        index--;
        continue;
      }
      else{
        int cnt = 1;
        int temp = 0;
        bool yes = true;
        for (int i = 1; i<=n; i++){
          if(temp+ a[i] < prefix[n]/index)
            temp+=a[i];
          else if (temp+a[i] == prefix[n]/index && i<n){
            temp = 0;
            cnt++;
          }
          else if (temp+a[i] > prefix[n]/index){
            yes = false;
            break;
          }
        }
        if(yes) yes = (cnt == index);
        if(yes){
          cout<<n-index<<endl;
          break;
        }
      }
      index--;
    }
  }
}
