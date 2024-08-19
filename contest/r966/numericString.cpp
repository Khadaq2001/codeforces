#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    const int num = 26;
    int n, m;
    cin >> n;
    vector<long> a(n);
    for (long &i : a)
        cin >> i;
    cin >> m;
    while (m--) {
        string b;
        cin >> b;
        if (b.length() != n) {
            cout << "NO" << endl;
            continue;
        } else {
            vector<bool> c(num, false);
            vector<long> map(num, 0);
            bool flag = true;
            for (int i = 0; i < n; i++) {
                int dig = b[i] - 97;
                if (!c[dig]) {
                    map[dig] = a[i];
                    c[dig] = true;
                } else {
                    if (map[dig] != a[i]) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
                cout << "YES" << endl;
            else
                cout << "NO" <<endl;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
