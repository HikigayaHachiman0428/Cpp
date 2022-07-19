#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll b;
ll prefix [50005];
int main()
{
    cin>>n>>b;
    int index;
    bool first = false;
    for (int i =1; i<=n; i++)
    {
        ll temp;
        cin>>temp;
        prefix[i] += temp;
        if (prefix[i] > b && !first)
        {
            index = i;
            first = true;
        }
    }
    for (int i =1; i<=n; i++)
    {
        while (prefix[index] - prefix[i-1] > b)
        {
            if (index%2 == 1)
                index--;
            else
                index-=2;
        }
        while(i + index > n )
    }
}