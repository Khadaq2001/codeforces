#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std; 


void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> loc(k);
    for (int i=0; i<k; i++){
         cin >> loc[i].second >> loc[i].first; // revert x and y for sorting convince;
    }
    sort (loc.begin(), loc.end());
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

