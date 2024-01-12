#include<iostream>
#include<string>
using namespace std;


bool in_case(string str){
    if (str.length() > 1) {
        for (int i =1; i < str.length(); i ++ ){
            if (islower(str[i]))
                return false;
        }
        return true;
    }
    return true;
}
string changeCase(string& str){
    string newStr = str;
    for (int i =0; i < str.length(); i ++ ){
        if (isupper(newStr[i] ))
            newStr[i] = tolower(str[i]); 
        else 
           newStr[i] = toupper(str[i]); 
    }

    return newStr;
}

int main(){
    string str, newStr;
    cin >> str;
    if (in_case(str)){
        newStr = changeCase(str);
    }
    else 
        newStr = str;
    cout << newStr << endl;
    return 0;

} 