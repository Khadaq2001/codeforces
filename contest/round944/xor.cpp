#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;


int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, priority_queue<int>> mp; 
        for (int &i : a){
            cin >> i;
            mp[i>>2].push(-i); 
        }
        for (int i=0; i<n; i++){
            cout << -mp[a[i]>>2].top() << " ";
            mp[a[i]>>2].pop();
        }
        cout << endl;
    }
    return 0;
}
