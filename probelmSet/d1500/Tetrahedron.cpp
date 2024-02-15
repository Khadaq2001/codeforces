#include <vector>
#include <iostream>
#define MAX 1000000007
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> dp(n + 1);
    vector<ll> N(n + 1);
    dp[1] = 0;
    dp[2] = 3;
    N[1] = 3;
    N[2] = 6;
    for (ll i = 3; i <= n; i++)
    {
        N[i] = (dp[i - 1] * 3 + N[i - 1] * 2) % MAX;
        dp[i] = (dp[i - 2] * 3 + N[i - 2] * 2) % MAX;
    }
    cout << dp[n]<< endl;
    return 0;
}