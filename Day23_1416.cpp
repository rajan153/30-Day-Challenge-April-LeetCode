class Solution {
public:
    int M = 1e9 + 7;
    int solve(string& s, int k, int idx, vector<int>& dp)
    {
        if(idx >= s.size())
            return 1;
        if(s[idx] == '0')
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        long long int ways = 0;
        long long int curr = 0;
        for(int i=idx; i<s.size(); i++)
        {
            curr = curr*10 + s[i] - '0';
            if(curr > k)
                break;
            ways = (ways + solve(s, k, i+1, dp)) % M;
        }
        return dp[idx] = ways;
    }
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(), -1);
        return solve(s, k, 0, dp);
    }
};
