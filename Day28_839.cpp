class Solution {
    private:
    bool solve(string s1, string s2)
    {
        int cnt = 0;
        for(int i = 0; i < s1.length(); i++)
        {
            if(s1[i] != s2[i]){
                cnt++;
                if(cnt > 2)
                    return false;
            }
        }
        return cnt == 2 || cnt == 0;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int grp = 0;
        int n = strs.size();
        if(n == 1) return 1;
        vector<bool> vis(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(vis[i]) continue;
            grp++;
            vis[i] = 1;
            queue<int> q;
            q.push(i);
            while(!q.empty())
            {
                string curr = strs[q.front()];
                q.pop();
                for(int j=0;j<n;j++)
                {
                    if(vis[j]) continue;
                    if(solve(curr, strs[j]))
                    {
                        q.push(j);
                        vis[j] = 1;
                    }
                }
            }
        }
        return grp;
    }
};
