#include <iostream> 
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll; 
ll t, n, s;
int digSum(ll n){
    ll res = 0;
    while (n){
        res += n % 10;
        n /= 10;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n >> s;
        int res = digSum(n);
        if (res < s){
            cout << 0 << endl;
            continue;
        }
        ll out = 0;
        ll tmp =n;
        ll tmp2 = tmp;
        int dig;
        int count = 0;
        while (res > s){
        dig = tmp / ll(pow(10, count)) % 10;
        out += (10 - dig)%10 * ll(pow(10, count++)); 
        tmp = n + out;
        res = digSum(tmp);
        }
        cout << out << endl;
    }
    return 0;
}