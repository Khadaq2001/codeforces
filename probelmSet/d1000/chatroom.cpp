#include <iostream>
#include <string>

using namespace std;

int main(){
    string target = "hello";
    string input;
    int k = 0;
    cin >> input;

    for (int i=0; i <= input.length(); i++){
        if (k == 5){
            cout << "YES" << endl;
            return 0;
        }
        if (input[i] == target[k]){
            k ++ ;
        }
    }
    cout << "NO" << endl;
    return 0;

}