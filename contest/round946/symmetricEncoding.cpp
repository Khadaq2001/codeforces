#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string a;
    cin >> a;
    string b = a;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int l = a.length() - 1;
    for (int i = 0; i<n ;i++){
        int idx = a.find(b[i]);
        b[i] = a[l-idx];
    }
    cout << b << endl;

}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
