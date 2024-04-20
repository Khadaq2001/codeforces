#include <iostream>
using namespace std;

int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int m, n, k;
        cin >> n >> m >> k;
        int tmp = n / m;
        if (n % m > 0)
            tmp++;
        if (n - tmp <= k)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
