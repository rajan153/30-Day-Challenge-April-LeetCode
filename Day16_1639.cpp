class Solution {
public:
    long long M = 1e9 + 7;
    int solve(vector<vector<int>>& freq, string& target, vector<vector<int>>& dp,
    int coIndx, int tarIndx)
    {
        if(tarIndx == target.size())
            return 1;
        if(coIndx == freq[0].size())
            return 0;
        if(dp[coIndx][tarIndx] != -1)
            return dp[coIndx][tarIndx];
        int targetCh = target[tarIndx] - 'a';
        int notP = solve(freq, target, dp, coIndx + 1, tarIndx);
        int pick = 0;
        if(freq[targetCh][coIndx] != 0)
        {
            int currWays = freq[targetCh][coIndx];
            int nextWays = solve(freq, target, dp, coIndx + 1, tarIndx + 1);
            pick = (currWays % M * nextWays % M) % M;
        }
        return dp[coIndx][tarIndx] = (pick % M + notP % M) % M;
    }
    int numWays(vector<string>& words, string target) {
        int m = words.size(), n = words[0].size();
        vector<vector<int>> freq(26, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                freq[words[i][j] - 'a'][j]++; 
            }
        }
        vector<vector<int>>dp(n, vector<int>(target.size(), -1));
        return solve(freq, target, dp, 0, 0);
    }
};
