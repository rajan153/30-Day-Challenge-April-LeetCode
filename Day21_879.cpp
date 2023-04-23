class Solution {
public:
    int m = 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int ret = 0;
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
        dp[0][0] = 1;
        for (int k = 0; k < group.size(); k++) {
            int p = profit[k];
            int g = group[k];
            for (int i = n - g; i >= 0; i--) {
                for (int j = minProfit; j >= 0; j--) {
                dp[i + g][min(minProfit, j + p)] += dp[i][j];
                dp[i + g][min(minProfit, j + p)] %= m;
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            ret += dp[i][minProfit];
            ret %= m;
        }
        return ret;
    }
};
