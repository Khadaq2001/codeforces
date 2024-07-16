#include <iostream>
#include <map>
#include <vector>
using namespace std;
const char *solve() {
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, int> stoNum;
    for (int &i : a) {
        cin >> i;
    }

    for (int &i : b) {
        cin >> i;
        stoNum[i] = 0;
    }
    cin >> m;
    vector<int> d(m);
    for (int &i : d) {
        cin >> i;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            stoNum[b[i]] ++;
    }
    for (int i = 0; i < m; i++) {
        if (stoNum.find(d[i]) != stoNum.end() && stoNum[d[i]] > 0)
            stoNum[d[i]] --;
    }
    for (auto &x : stoNum) {
        if (x.second > 0)
            return "NO";
    }
    if (stoNum.find(d[m-1]) != stoNum.end())
        return "YES";
    return "NO";
}
int main() {
    int t;
    cin >> t;
    while (t--)
        cout << solve() << endl;
}
