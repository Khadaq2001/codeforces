#include <iostream>
#include <vector>
using namespace std;

int calculatePenalty(vector<vector<int>> dp, int idx){
    ;
}
int minizePenalty(const vector<long> &arr, int n)
{
    vector< vector<int>>  dp(n, vector(n, -1));
    dp[0][0] = 0;
    for (int i =1; i<n ; i++){
        ; 
    }
}
int main()
{
    int n, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<long> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int minPenalty = minizePenalty(arr, n);
    }
}