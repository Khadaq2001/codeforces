#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve() {
    int m, n;
    int out = 0;
    int tmp;
    cin >> n >> m;
    string a;
    vector<int> b(7, m);
    cin >> a;
    for (int i = 0; i < n; i++) {
        b[a[i]-65]--;
    }
    for (int i = 0; i < 7; i++) {
        int nums = b[i] > 0 ? b[i] : 0;
        out += nums;
    }
    cout << out << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
