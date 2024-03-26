#include <iostream>
#include <vector>
#include <queue> 

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    priority_queue<ll, vector <ll>, greater<ll>> pq; // smallest element first 
    ll S = 0;
    for (int i =0; i < n; i++){
        ll x;
        cin >> x;
        S +=x;
        pq.push(x);
        while (S<0){
            S -= pq.top();
            pq.pop();
        }
    }
    cout << (int) pq.size() << endl;

    return 0;

} 