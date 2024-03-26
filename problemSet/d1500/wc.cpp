#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{ // greedy algothrim
    ll n;
    cin >> n;
    ll fallen = 0;
    vector<ll> x(n), h(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> x[i] >> h[i];
    }
    for (ll i=0; i<n; i++){
        if (i==0 || i==n-1)
        {
            fallen ++; // first and last tree always fall
            continue;
        }
        if (x[i]-h[i]>x[i-1]) // fall to the left
        {
            fallen++;
            continue;
        }
        if (x[i] + h[i] < x[i+1]) // fall to the right 
        {
            fallen++;
            x[i] += h[i];
            continue;
        }
    }
    cout << fallen << endl;
    return 0;
}