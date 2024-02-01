#include<iostream>
#include<string>

using namespace std;
typedef long long ll ;

int main(){
    string str;
    ll out;
    getline(cin,str);
    ll len=str.size();
    for (char c:str){
        if (c % 8 == 0 ){
            cout << "YES\n" << c << endl;
            return 0;
        }
    }
    for (int i=0; i < len-1; i++){
        for (int j=i+1; j < len; j++){
            out = stoi(str.substr(i,1)+str.substr(j,1));
            if (out%8==0){
                cout << "YES\n" << out << endl;
                return 0;
            }
        }
    }
    for (int i=0; i < len-2; i++){
        for (int j=i+1; j < len-1; j++){
            for (int k=j+1; k < len; k++){
                out = stoi(str.substr(i,1)+str.substr(j,1)+str.substr(k,1));
                if (out%8==0){
                    cout << "YES\n" << out << endl;
                    return 0;
                        }
                    }
                }
            }

    cout << "NO" << endl;
    return 0;
        }
    

