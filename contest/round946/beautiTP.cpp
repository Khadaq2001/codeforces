#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct VectorHash {
  size_t operator()(const std::vector<int> &v) const {
    size_t seed = 0;
    for (int i : v) {
      seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};

size_t solve(int n) {
  vector<int> a(n);
  for (int &i : a)
    cin >> i;
  size_t ans = 0;
  vector<vector<int>> trips(3, vector<int>(3));
  vector<int> triplet(3);
  unordered_map<vector<int>, size_t, VectorHash> map;
  for (int i = 0; i < n - 2; i++) {
    triplet = {a[i], a[i + 1], a[i + 2]};
    for (int j = 0; j < 3; j++) {
      trips[j] = triplet;
      trips[j][j] = 0;
      ans += map[trips[j]] - map[triplet];
      map[trips[j]]++;
    }
    map[triplet]++;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << solve(n) << endl;
  }
}
