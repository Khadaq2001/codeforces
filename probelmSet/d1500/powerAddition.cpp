#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

ll t, n;
int main() {    
    cin >> t;
    for (int i =0 ;i <t ;i++){
        cin >> n;
        ll x = 0;
        ll max =0;
        ll diff=0;
        vector <ll> a(n);
        vector <ll> b(n);
        for (ll j=0; j <n ; j++)
            cin >> a[j];
        b[0] = a[0];
        for (ll j=1; j<n; j++){
            b[j] = a[j]>b[j-1]?a[j]:b[j-1];
        }
        for (ll j=0; j<n; j++){
            diff = b[j] - a[j];
            if (diff > max){
                max = diff;}
        }

        while (max >0){
            max -= pow(2,x++);
        }
        cout << x << endl;
    }
     
}
