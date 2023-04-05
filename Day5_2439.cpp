int minimizeArrayValue(vector<int>& nums) {
        long sum = 0;
        long rem = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            rem = max(rem, (sum + i)/(i + 1));
        }
        return rem;
    }
// T.C. O(N)
// S.C. O(1)
