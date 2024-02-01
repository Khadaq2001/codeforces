#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int MAXN = 101;
bool dp[MAXN][8];
int pre[MAXN][8];

int main(){
    string s;
    getline(cin,s);
    int n = s.size();
    memset(pre, -1, sizeof(pre));
    dp[0][(s[0]-'0')%8] = true;
    
    for (int i=1; i<n; i++){
        dp[i][(s[i]-'0') % 8] = true;
        
        for(int j=0; j <8; j++){
            if (dp[i-1][j]){
                dp[i][j] = true;
                pre[i][j] = j;
                dp[i][(j*10 + s[i]-'0') % 8] = true;
                pre[i][(j*10 + s[i]-'0') % 8] = j;
            }
        }
    }
    for (int i=0; i<n; i++){
        if (dp[i][0]){
            string ans = "";
            int curI = i, curJ = 0;
            while (1){
                if (pre[curI][curJ] == -1 || pre[curI][curJ] != curJ){
                    ans += s[curI];
                }
                if (pre[curI][curJ] == -1) break;
                
                curJ = pre[curI][curJ];
                curI--;
                
            } 
            cout << "YES\n" << ans << endl;
            return 0;
        }
    }
    cout << "NO\n" ;
    return 0;
     
}