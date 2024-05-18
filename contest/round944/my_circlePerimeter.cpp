#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int r;
        cin >> r;
        int r2 = pow(r, 2);
        int rp2 = pow(r + 1, 2);
        int rm = sqrt(r2 / 2);
        ll ans = 0;
        ll rep = 0;
        for (int x = r; x >= rm; x--)
            for (int y = x; y > 0; y--) {
                ll x2 = pow(x, 2);
                ll y2 = pow(y, 2);
                if (x2 + y2 >= r2) {
                    if (x2 + y2 < rp2) {
                        ans++;
                        if (x == y)
                            rep++;
                    }
                }
                else 
                    break;
            }
        ans = ans * 8 - rep * 4 + 4;
        cout << ans << endl;
    }
}
