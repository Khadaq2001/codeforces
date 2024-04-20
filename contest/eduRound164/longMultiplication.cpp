#include <iostream>
#include <string>

using namespace std;

void solve(string &x, string &y) {
    int n = x.size();
    int j = 0;
    while (x[j] == y[j])
        j++;
    if (int(x[j]) < int(y[j])) {
        string tmp = x;
        x = y;
        y = tmp;
    }
    for (int i = j + 1; i < n; i++) {
        if (x[i] > y[i])
            swap(x[i], y[i]);
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        solve(x, y);
        cout << x << '\n';
        cout << y << '\n';
    }
    return 0;
}
