#include <iostream>
#include <string>
using namespace std;

int main(){
  string s; int useless; cin>>useless;
  cin>>s;
  for (int length = 1; length<=s.length(); length++){
    for (int i = 0; i<=s.length()-length; i++){
      cout<<i<<i+length<<endl;
      string cur = s.substr(i, i+length);
      string cut = s.substr(0, i)+s.substr(i+length);
      cout<<cur<<" "<<cut<<endl;
      if (cut.find(cur)==string::npos){
        cout<<length;
        return 0;
      }
    }
  }
}
