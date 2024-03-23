#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll x[n], h[n], left[n], right[n], stay[n];
    left[0] = right[0] = stay[0] = 0;
    for (int i=0; i<n; i++)
        cin >> x[i] >> h[i]; 
    
    for (ll i = 2; i < n; i++)
    {
        ll x, h;
        cin >> x >> h;
    }
}