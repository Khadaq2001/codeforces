#include <iostream>
using namespace std;

bool is_lucky(int n){
    int digit;
    while(n > 0 ){
        digit = n % 10;
        if (digit != 4 && digit != 7)
            return false;
        n /= 10;
    }
    return true;
}

bool is_almost_lucky(int n){
    for (int i=1; i<n; i ++){
        if (is_lucky(i))
            if (n % i == 0)
                return true;
    }
    return false;
}


int main(){
    int n;
    scanf("%d", &n);
    if (is_lucky(n))
        cout << "YES"<< endl;
    else if  (is_almost_lucky(n))
        cout << "YES"<< endl; 
    else 
        cout << "NO" << endl;

    return 0;
}