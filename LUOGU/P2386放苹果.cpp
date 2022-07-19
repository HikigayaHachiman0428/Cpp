#include <bits/stdc++.h>
using namespace std;
/*
n个盘子，m个苹果
f[m][n]
构造
1，n > m, f[m][n] = f[m][m]
2, n <= m
          2.1 至少有一个盘子空的
          f[m][n] = f[m][n-1]
          2.2 全有苹果
          f[m][n] = f[m-n][n]

          f[m][n] = f[m][n-1] + f[m-n][n]
*/
int main()
{
    
}