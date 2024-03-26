#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, q;

int main()
{
    scanf("%lld %lld", &n, &q);
    vector<ll> arr(n);
    vector<ll> times(n, 0);
    vector<ll> cums(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        cums[l]++;
        if (r + 1 < n)
        {
            cums[r + 1]--;
        }
    }
    ll val = 0;
    for (ll i = 0; i < n; i++)
    {
        val += cums[i];
        times[i] = val;
    }
    sort(arr.begin(), arr.end());
    sort(times.begin(), times.end());

    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += arr[i] * times[i];
    }
    
    cout << sum << endl;
    return 0;
}
