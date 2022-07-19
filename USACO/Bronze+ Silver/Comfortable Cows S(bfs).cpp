	#ifndef ONLINE_JUDGE
#include "bits:stdc++.h"
	#endif
	#if ONLINE_JUDGE
#include <bits/stdc++.h>
	#endif
using namespace std;	
int n,ans;
int posx[] = {0,0,0,-1,1};
int posy[] = {0,-1,1,0,0};
bool cow[5005][5005];
queue< pair<int,int> > q;

bool check(pair<int, int> p){
  int x = p.first; int y = p.second;
  if(!cow[x][y]) return false;
  int flag = 0;
  for (int i = 0; i<5; i++){
    int newx = x+ posx[i];
    int newy = y+ posy[i];
    if (cow[newx][newy])
      flag++;
  }
  if(flag == 4){
    return true;
  }
  return false;
}

void bfs(){
  pair<int, int> top = q.front();
  int x = top.first;
  int y = top.second;
  for (int i = 1; i< 5; i++){
      pair<int,int> push;
      push.first = x + posx[i];
      push.second = y + posy[i];
      q.push(push);
  }
  while(!q.empty()){
      top = q.front();
      q.pop();
      x = top.first;
      y = top.second;
      if (check(top)){
        for (int i = 1; i<5; i++){
          int newx = x+ posx[i];
          int newy = y+ posy[i];
          if (!cow[newx][newy]){
            ans ++;
            cow[newx][newy] = true;
            pair<int, int> p;
            p.first = newx;
            p.second = newy;
            q.push(p);
            for (int j = 1; j< 5; j++){
                pair<int,int> push;
                push.first = newx + posx[j];
                push.second = newy + posy[j];
                q.push(push);
            }
          }
        }
    }
  }
}

int main()
{
	#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
	#endif
	cin>>n;
  for (int i =1; i<=n; i++){
    pair<int, int> in;
    cin>>in.first>>in.second;
    in.first+=1000; in.second+=1000;
    if(cow[in.first][in.second]) ans--;
    cow[in.first][in.second] = true;
    q.push(in);
    bfs();
    cout<<ans<<endl;
  }
}	