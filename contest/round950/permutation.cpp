#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for (auto &i : V)
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        return hash;
    }
};

const char *solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m, 0)), b(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    unordered_map<vector<int>, bool, VectorHasher> rows;
    for (int i = 0; i < n; i++) {
        vector<int> tmp(m);
        for (int j = 0; j < m; j++)
            tmp[j] = a[i][j];
        sort(tmp.begin(), tmp.end());
        rows[tmp] = true;
    }
    for (int i = 0; i < n; i++) {
        vector<int> tmp (m);
        for (int j = 0; j < m; j++)
            tmp[j] = b[i][j];
        sort(tmp.begin(), tmp.end());
        if (rows.find(tmp) == rows.end())
            return "NO";
    }

    unordered_map<vector<int>, bool, VectorHasher> columns;
    for (int j = 0; j < m; j++) {
        vector<int> tmp(n);
        for (int i = 0; i < n; i++) {
            tmp[i] = a[i][j];
        }
        sort(tmp.begin(), tmp.end());
        columns[tmp] = true;
    }
    for (int j = 0; j < m; j++) {
        vector<int> tmp(n);
        for (int i = 0; i < n; i++) {
            tmp[i] = b[i][j];
        }
        sort(tmp.begin(), tmp.end());
        if (columns.find(tmp) == columns.end())
            return "NO";
    }
    return "YES";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}
