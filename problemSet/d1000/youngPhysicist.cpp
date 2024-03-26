#include<iostream>

using namespace std;

int main(){
    int x=0,y=0,z=0;
    int x_temp, y_temp, z_temp;
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x_temp >> y_temp >> z_temp; 
        x += x_temp;
        y += y_temp;
        z += z_temp;
    }

    if (x == 0 && y == 0 & z==0)
        cout << "YES" <<endl;
    else 
        cout << "NO" << endl;
    
    return 0;
}