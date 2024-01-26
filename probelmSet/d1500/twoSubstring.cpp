#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

int main(){
    string str;
    vector<int> a,b;
    cin >> str;
    int len = str.size();
    for (int i=0;i<len-1; i ++){
        if (str[i]=='A' && str[i+1]=='B')
            a.push_back(i);
        if (str[i]=='B' && str[i+1]=='A')
            b.push_back(i);
       }
    if (!a.empty() && !b.empty()){
        int max1=a.front() - b.back();
        int max2=b.front() - a.back();
        if (abs(max1) > 1 || abs(max2) >1)
            cout << "YES"<<endl;
        else 
            cout << "NO" << endl;
    }
    else
        cout <<"NO"<<endl;
    return 0;


}
