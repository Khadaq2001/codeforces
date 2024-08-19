#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, chicken, cow;
        cin >> n;
        cow = n / 4;
        chicken = (n % 4) / 2;
        cout << cow + chicken << endl;
    }
}
