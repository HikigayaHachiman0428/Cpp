#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
/*
6 5 5 1 1 2 3 4 5 5 5 1 1 2 3 5 4 5 5 1 1 2 4 5 3 5 5 2 1 2 4 5 3 3 10 2 1 3 2 1 3 2 1 3 2 1 3 10 1 1 3 2 1 3 2 1 3 2 1
*/
const int maxn = 2e5+5;
const int maxm = 1e4+5;
int ma[maxn], cnt[maxm];
int main(){
  int t; cin>>t;
  for (int index = 1; index<=t; index++){
    int m, n, k;
    cin>>m>>n>>k; // mailbox:1-m; mail: 1-n
    memset(ma, 0, sizeof(ma));
    memset(cnt, 0, sizeof(cnt));
    for (int i =1; i<=n; i++){
      cin>>ma[i];
      cnt[ma[i]]++;
    }
    int mail = 1; int mailbox = 1;
    stack<int> wait; bool flag = true;
    priority_queue<int, vector<int> , greater<int> > screen;
    while(mail <= n - wait.size()){
      while (screen.size() < k){
        screen.push(ma[mail]);
        mail++;
      }
      if(screen.top()<=min(mailbox+k-1,m) && screen.top() >= mailbox){
        cnt[screen.top()]--;
        screen.pop();
      }
      else{
        if (cnt[mailbox] == 0){
          mailbox++;
          if (mailbox>m){
            flag = false;
            break;
          }
        }
        else if (screen.top() > m){
          flag = false;
          break;
        }
        else{
          wait.push(screen.top());
          screen.pop();
        }
        if (wait.size() > k){
          flag = false;
          break;
        }
      }
    }
    while(flag && !wait.empty()){
      int temp = wait.top(); wait.pop();
      if(temp<=max(mailbox+k-1,m) && temp >= mailbox){
        cnt[temp]--;
      }
      else{
        if (cnt[mailbox] == 0){
          mailbox++;
          if (mailbox>m){
            flag = false;
          }
        }
        else{
          flag = false;
        }
    }
  }
  if (flag) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
}
