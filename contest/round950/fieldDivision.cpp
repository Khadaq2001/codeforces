#include <iostream>
#include <vector>

using namespace std;

void solve();

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> locs;
    for (int i=0; i<k; i++){
        cin >> locs[i].second >> locs[i].first; // revert order of x and y for sorting 
    }
    

}
