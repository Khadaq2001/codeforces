#include <iostream> 
#include <vector>

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
            return 0;
        }
        ll out = 0;
        ll tmp = n; 
        int count = 0;
        while (res > s){
        int dig = tmp % 10;
        tmp /= 10;
        out += (10 - dig) * 10^(count++); 
        n += out;
        res = digSum(n);
        }
        cout << out << endl;
    }
}