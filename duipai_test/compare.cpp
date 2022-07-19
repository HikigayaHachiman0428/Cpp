#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <fstream>
#include <cassert>
#include <string>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;

void readData(string file)
{
    ifstream infile; 
    infile.open(file.data());   //将文件流对象与文件连接起来 
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

    string s;
    while(getline(infile,s))
    {
        cout<<s<<endl;
    }
    infile.close();             //关闭文件输入流 
}

void readans(string file1, string file2){
    ifstream infile1, infile2;
    infile1.open(file1.data());
    infile2.open(file2.data());
    assert(infile1.is_open());    
    assert(infile2.is_open());    
    string s1, s2;
    while(getline(infile1, s1) && getline(infile2, s2)){
        bool flag = false;
        if(s1 != s2) flag = true;
        if(flag) printf("------------------\n");
        cout << s1 <<  " | " <<s2 << endl;
        if(flag) printf("------------------\n");
    }
    infile1.close();
    infile2.close();
}

int main(){
  for (int i=1;;i++){
        printf("The result of No. %d Case is:  ",i);
        system("./data");//程序路径
        system("./test1");
        system("./test2");
        if (system("diff test1.out test2.out")){
            printf("Wrong Answer\n");
            printf("The input is ");
            readData("./test.in");
            printf("\n"); 
            //直接输出数据和答案， 方便比较
            readans("./test1.out", "./test2.out");
            //同步输出两组数据， 方便对比查看。
            return 0;
        }
        else printf("Accepted\n");
        if (i >= 5000){
            cout<<"no problems detected!"<<endl;
            break;
        }
    }
    return 0;
}
