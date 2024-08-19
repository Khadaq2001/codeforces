#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int tmp;
    int x = k, y = k;
    for (int i = 0; i < n; i++) {
        if (x == 1) {
            for (int j = 0; j < n; j++) {
                cin >> tmp;
                if (y == 1) {
                    cout << tmp;
                    y = k;
                } else {
                    y--;
                }
            }
            x = k;
        } else {
            x--;
            for (int j = 0; j < n; j++) {
                cin >> tmp;
            }
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
