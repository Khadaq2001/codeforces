#include <iostream>

using namespace std;

int solve(int x, int y) {
    int yScreen = 0;
    int ans = 0;
    if (y > 0){
        yScreen = (y + 1) / 2;
        x -= (yScreen-1) * 7;
        if (y % 2)
            x -= 11;
        else 
            x -= 7;
    }
    ans += yScreen;
    if (x > 0){
        ans += x / 15;
        int mod = x % 15;
        if (mod)
            ans ++;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int x, y;
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }
    return 0;
}
