#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    ll n, total = 0;
    ll h = 0;
    cin >> n;
    vector<ll> arr(n);
    vector<vector <ll>> dp(n,vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    ll k = 0;
    if (arr[0]>0){
        k++;
        dp[0][0]=arr[0];
    }
    for (int i = 1; i < n; i++)
    {
        if (dp[i-1][k-1] + arr[i] >0)
        {
            dp[i][k] = dp[i-1][k-1] + arr[i];
            dp[i][k-1] =
        } 
        else 
        {
            
        }
    }
    
    return 0;
}