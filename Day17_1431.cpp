//T.C. O(N)*2
//S.C. O(N)
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        for(int i = 0; i < candies.size(); i++)
        {
            bool test = false;
            for(int j = 0; j < candies.size(); j++)
            {
                if(candies[i]+extraCandies < candies[j]){
                    test = true;
                    break;
                }
            }
            if(test)
                result.push_back(false);
            else
                result.push_back(true);
        }
        return result;
    }
};
//T.C. O(N)
//S.C. O(N)
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maxi = INT_MIN;
        for(int i=0;i<candies.size();i++)
        {
            maxi = max(maxi, candies[i]);
        }
        for(int v: candies)
        {
            result.push_back(v >= maxi - extraCandies);
        }
        return result;
    }
};
