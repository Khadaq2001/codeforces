#include <iostream>
#include <vector>
using namespace std;
const char *solve() {
    const int MAX = 1000000001;
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &i : a) {
        cin >> i;
    }

    for (int &i : b) {
        cin >> i;
    }
    cin >> m;
    vector<int> d(m);
    for (int &i : d) {
        cin >> i;
    }
    int diff = 0;
    vector<int> map(MAX, 0);
    for (int i=0; i<n; i++){

        
    }
    return "YES";
}


int main() {
    int t;
    cin >> t;
    while (t--)
        cout << solve() << endl;
}
