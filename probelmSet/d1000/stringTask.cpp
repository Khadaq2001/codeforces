#include<iostream>
#include<string> 
#define LEN 100;
using namespace std;

bool is_vowels(char c){
    string vowels = "aeiouy";
    for(int i=0; i<vowels.length(); i++){
        if(c == vowels[i]) return true;
    }
    return false; 
}

int main(){
    string s, out;
    cin>>s;
    for(int i=0; i<s.length(); i++){
        if(!is_vowels(tolower(s[i]))){
            out += '.';
            out += tolower(s[i]);
        }
    }
    cout << out << endl;
    return 0;
}