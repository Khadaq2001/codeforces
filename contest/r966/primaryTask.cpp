#include <iostream>
#include <string>
using namespace std;

string isImportant(string n) {
    if (n.length() < 3)
        return "NO";
    if (n[0] == '1' && n[1] == '0') {
        if (n.length() ==  3 && (n[2] == '0' || n[2] == '1'))
            return "NO";
        if (n[2] == '0')
            return "NO";
        else
            return "YES";
    }
    else {
        return "NO";
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        cout << isImportant(n) << endl;
    }
}
