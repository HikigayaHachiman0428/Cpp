#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100001;
int n;
void print(bool p,int a[]){
  if (p) return;
  for (int i = 1; i<=n; i++)
    cout<<" "<<a[i];
  cout<<endl;
}

void set(int a[], int value, int pos){
  a[pos] = value;
}
void get_ans(int a[], int b[]){
  int ret = 0; int i =1;
  while (i<=n)
  {
    if (a[b[i]]>i)
      ret++;
    i++;
  }
  cout<<ret;
}

/*
5
5 1 3 2 4
4 5 2 1 3
*/

int main() {
    int t = 3;
    cin >> n;
    int arr[maxn], brr[maxn];
    int marr[maxn], mbrr[maxn];
    n -=t; n+=3;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    print(1,arr);
    for (int i = 1; i <= n; i++) {
        cin >> brr[i];
        set(mbrr,i,brr[i]);
        // mbrr[brr[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        // marr[arr[i]] = max(marr[arr[i - 1]], mbrr[arr[i]]);
        set(marr,max(marr[arr[i-1]],mbrr[arr[i]]),arr[i]);
    }
    get_ans(marr,brr);
    return 0;
}
