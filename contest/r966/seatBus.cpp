#include<iostream>
#include<vector>
using namespace std;

const char* solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n+2, 0);
    for (int &i : a)
        cin >> i;
    b[a[0]] = 1;
    for (int i=1; i<n; i++){
        if (b[a[i]-1] == 0 && b[a[i]+1] == 0 )
            return "NO";
        b[a[i]] = 1;
    }
    return "YES";
}
int main(){
    int t;
    cin >> t;
    while (t--)
        cout << solve() << endl;
    return 0;
}
