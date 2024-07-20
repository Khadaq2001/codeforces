#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (a < b)
        swap(a, b);
    int c = a % b;
    while (c) {
        a = b;
        b = c;
        if (b == 1)
            break;
        c = a % b;
    }
    return b;
}
int getIndex(vector<int> &a) {
    int pre = -1;
    for (int i = 0; i < a.size() - 1; i++) {
        int b = gcd(a[i], a[i + 1]);
        if (b < pre) {
            return i;
        }
        pre = b;
    }
    return a.size()-1;
}

bool good(vector<int>& a){
    return (getIndex(a) == a.size()-1);
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int violate, seg, index;
    for (int &i : a)
        cin >> i;
    int i = getIndex(a);
    if (i == n-1){
        cout << "YES" << endl;
        return;
    } 
    vector<int> a0 = a, a1 = a, a2 =a;
    if (i > 0)
        a0.erase(a0.begin() + i -1);
    a1.erase(a1.begin()+i);
    if (i<n-1)
        a2.erase(a2.begin()+i+1);

    if (good(a0) || good(a1) || good(a2)){
        cout << "YES" << endl; 
        return;
    }
    else
        cout << "NO" << endl; 
    
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
