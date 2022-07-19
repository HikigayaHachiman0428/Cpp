#include <iostream>
#define mod 10007
using namespace std;
int n, m;
long long ans;
int color[100005], num[100005];
long long self_product[2][100001], sum_of_index[2][100001], sum_of_num[2][100001];
namespace brute
{
    void solve()
    {
        long long ans = 0;
        for (int i = 1; i <= n - 2; i++)
            for (int j = 0; j * 2 + 1 + i + 1 <= n; j++)
            {
                if (color[i] == color[j * 2 + 1 + i + 1])
                {
                    // cout<<i<<" "<<j*2 + 1 + i + 1<<endl;
                    ans += (j * 2 + 1 + i + 1 + i) * (num[i] + num[j * 2 + 1 + i + 1]) % mod;
                    ans %= mod;
                }
            }
        cout << ans << endl;
        return;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> color[i];
        // cout<<self_product[i%2][color[i]]<<" "<<sum_of_index[i%2][color[i]]<<" "<<sum_of_num[i%2][color[i]]<<endl;
        if (sum_of_index[i % 2][color[i]] != 0)
        {
            ans += self_product[i % 2][color[i]] % mod;
            ans %= mod;
            ans += (sum_of_index[i % 2][color[i]] + sum_of_index[(i + 1) % 2][color[i]]) * num[i] % mod;
            ans %= mod;
            ans += (sum_of_num[i % 2][color[i]] + sum_of_num[(i + 1) % 2][color[i]]) * i % mod;
            ans %= mod;
        }
        self_product[i % 2][color[i]] += i * num[i] % mod;
        self_product[i % 2][color[i]] %= mod;
        sum_of_index[i % 2][color[i]] += i;
        sum_of_num[i % 2][color[i]] += num[i];
        cout << self_product[i % 2][color[i]] << " " << sum_of_index[i % 2][color[i]] << " " << sum_of_num[i % 2][color[i]] << endl;
        cout << ans << endl
             << "\n";  
    }
    // brute::solve();
    // cout<<ans;
    return 0;
}