#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    char s[n];
    char o[n];
    for (char &i : s)
        cin >> i;
    int x = 0, y = 0;
    for (char &i : s) {
        switch (i) {
        case ('N'):
            y++;
            break;
        case ('S'):
            y--;
            break;
        case ('W'):
            x--;
            break;
        case ('E'):
            x++;
            break;
        default:
            break;
        }
    }
    if (abs(x) % 2 == 1 || abs(y) % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    bool xSign = x > 0;
    bool ySign = y > 0;
    int xDest = abs(x) / 2;
    int yDest = abs(y) / 2;
    if (yDest == 0 && xDest == 0) {
        if (n == 2) {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        char dir = s[i];
        if (i == 0 && yDest == 0 && xDest == 0) {
            cout << 'H';
            if (dir == 'E') {
                xSign = false;
                xDest++;
            }
            if (dir == 'W') {
                xSign = true;
                xDest++;
            }
            if (dir == 'N') {
                ySign = false;
                yDest++;
            }
            if (dir == 'S') {
                ySign = true;
                yDest++;
            }
            continue;
        }
        if (xSign && xDest) {
            if (dir == 'E') {
                cout << 'H';
                xDest--;
                continue;
            }
        }
        if (!xSign && xDest) {
            if (dir == 'W') {
                cout << 'H';
                xDest--;
                continue;
            }
        }
        if (ySign && yDest) {
            if (dir == 'N') {
                cout << 'H';
                yDest--;
                continue;
            }
        }
        if (!ySign && yDest) {
            if (dir == 'S') {
                cout << 'H';
                yDest--;
                continue;
            }
        }
        cout << 'R';
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
