#include <iostream>
#include <vector>

using namespace std;

int n;

int solution (vector<int> &a)
{
    int preStatus = 0;
    for (int i = 0; i<n ; i++)
    {
        int status = 0;
        if(a[i] == 1 && preStatus != 1)
            ; 
        
    }
}

int main(){
    cin >> n;
    vector<int> a(n);
    for (int &day : a)
        cin >> day;
    int ans = solution(a);
    cout << ans << endl;
}
