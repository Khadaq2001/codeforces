#include <iostream>
#include <vector>

using namespace std;

int solve(int n) {
    int rm = n;
    int tmp = -1;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    for (int i = 0; i < n; i++) {
        if (a[i] != a[0]) {
            rm = min(rm, i - tmp - 1);
            tmp = i;
        }
    }
    rm = min(rm, n - 1 - tmp);
    if (rm == n)
        rm = -1;
    return rm;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
