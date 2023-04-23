class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        if(word1 == "")
            return word2;
        if(word2 == "")
            return word1;
        int n = word1.size();
        int m = word2.size();
        int i = 0, j = 0;
        string ans;
        while(i < n && j < m)
        {
            ans.push_back(word1[i]);
            i++;
            ans.push_back(word2[j]);
            j++;
        }
        while(i < n)
        {
            ans.push_back(word1[i]);
            i++;
        }
        while(j < m)
        {
            ans.push_back(word2[j]);
            j++;
        }
        return ans;
    }
};
