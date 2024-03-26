#include <iostream>
#include <vector>

using namespace std;

int n;

int solution(int n)
{
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    vector<vector<int>> dp(n, vector<int>(3, 0)); // store the maxium working days
    if (a[0] == 1)
        dp[0][1] = 1;
    if (a[0] == 2)
        dp[0][2] = 1;
    if (a[0] == 3)
    {
        dp[0][1] = 1;
        dp[0][2] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        int tmp = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][0] = max(tmp, dp[i - 1][2]);
        if (a[i] == 1 || a[i] == 3)
            dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][2] + 1);
        if (a[i] == 2 || a[i] == 3)
            dp[i][2] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
    }
    int tmp = max(dp[n - 1][0], dp[n - 1][1]);
    int maxWorkDay = max(tmp, dp[n - 1][2]);
    return n - maxWorkDay;
}

int main()
{
    cin >> n;
    int ans = solution(n);
    cout << ans << endl;
    return 0;
}
