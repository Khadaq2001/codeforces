#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
typedef unsigned long long ll;
const int MOD = 998244353;

ll mul(int x, int y) { return x * 1LL * y % MOD; }

ll add(int x, int y) { return (x + y) % MOD; }

int main() {
    int n;
    ll ans = 0;
    cin >> n;
    vector<ll> a(n);
    for (ll &i : a) {
        cin >> i;
    }
    ll s = accumulate(a.begin(), a.end(), 0);
    vector<int> dp(s + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = s - a[i]; j >= 0; j--)
            dp[j + a[i]] = add(dp[j + a[i]], dp[j]);
    for (int i = 0; i <= s; i++) {
        ans = add(ans, mul((i + 1) / 2, dp[i]));
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < a[i]; ++j)
            ans = add(ans, mul(a[i] - (a[i] + j + 1) / 2, dp[j]));
    cout << ans << endl;
    return 0;
}
