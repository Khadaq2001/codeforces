#include <iostream>
<<<<<<< HEAD
#include <vector>
=======
<<<<<<< HEAD
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
=======
#include <vector> 
>>>>>>> 2242e3b943beecdcd9282224ba76ab02d5ece646
#include <algorithm>
using namespace std;

>>>>>>> 1aa9b031632aeeccca56ee1a2c55a5695938b827

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
<<<<<<< HEAD
    vector<pair<int, int>> locs;
    for (int i=0; i<k; i++){
        cin >> locs[i].second >> locs[i].first; // revert order of x and y for sorting 
    }
    

}
=======
    vector<pair<int, int>> loc(k);
    for (int i=0; i<k; i++){
         cin >> loc[i].second >> loc[i].first; // revert x and y for sorting convince;
    }
    int a = 0;
    int currentX=0, currentY=0;
    for (auto &i : loc){
       if ( i.second < currentX )
            continue;
        a += i.first ;
        currentY = i.first;
        currentX = i.second;
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve ();
    }
    return 0;
}
<<<<<<< HEAD
=======

>>>>>>> 1aa9b031632aeeccca56ee1a2c55a5695938b827
>>>>>>> 2242e3b943beecdcd9282224ba76ab02d5ece646
