#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    string output[3];
    int out;
    getline(cin,str);
    
    maxlen=  str.size();
    if (maxlen > 
    for(int i=0;i<maxlen-2; i++){
        for (int j=1; j<maxlen-1; j++){
            for (int k=2; k< maxlen; k++){
                out = (str[i]-'0')*100 + (str[j]-'0')*10 + (str[k]-'0') *1; 
                if (out % 8 ==0){
                   cout << "YES" << endl << out << endl;
                   return 0;
                }
            }
        }
    }
    cout << "NO" << endl;

}
