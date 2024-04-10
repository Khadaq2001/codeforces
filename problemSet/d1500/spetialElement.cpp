#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  ll t;
  ll n;
  cin >> t;
  while (t--) {
    ll ans = 0;
    cin >> n;
    vector<ll> arr(n, 0);
    vector<ll> cnt(n + 1, 0);
    for (ll &i : arr) {
      cin >> i;
      cnt[i]++;
    }
    for (int l = 0; l < n; l++) {
      ll sum = 0;
      for (int r = l; r < n; r++) {
        sum += arr[r];
        if (l == r)
          continue;
        if (sum > n) {
          break;
        } else {
          ans += cnt[sum];
          cnt[sum] = 0;
        }
      }
    }
    cout << ans << endl;
  }
}
