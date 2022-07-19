#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        int steps[105];
        steps[1] = 1;
        steps[2] = 2;
        steps[3] = 4;
        for (int i = 4; i<=n; i++)
            steps[i] = steps[i-1] + steps[i-2] + steps[i-3];
        cout<<steps[n]<<endl;
    }
}
