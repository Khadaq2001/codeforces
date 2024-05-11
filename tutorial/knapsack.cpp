#include <vector>
using namespace std;

int knapSackRecur(int W, vector<int> wt, vector<int> val, int n) {
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSackRecur(W, wt, val, n - 1);

    else
        return max(val[n - 1] + knapSackRecur(W - wt[n - 1], wt, val, n - 1),
                   knapSackRecur(W, wt, val, n - 1));
}

int knapSackDp(int W, vector<int> wt, vector<int> val, int index,
               vector<vector<int>> dp) {
    if (index < 0)
        return 0;
    if (dp[index][W] != -1)
        return dp[index][W];

    if (wt[index] > W) {
        dp[index][W] = knapSackDp(W, wt, val, index - 1, dp);
        return dp[index][W];
    }

    else {
        dp[index][W] =
            max(val[index] + knapSackDp(W - wt[index], wt, val, index - 1, dp),
                knapSackDp(W, wt, val, index - 1, dp));
        return dp[index][W];
    }
}

int knapSack(int W, vector<int> wt, vector<int> val, int n) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return knapSackDp(W, wt, val, n - 1, dp);
}
