class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int , vector<int>> adj;
        int n = colors.size();
        vector<int> indegree(n, 0);
        for(auto &vec : edges)
        {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<vector<int>> t(n, vector<int>(26,0));
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0){
                q.push(i);
                t[i][colors[i] - 'a'] = 1;
            }
        }
        int ans = 0;
        int cnt = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            cnt++;
            ans = max(ans, t[u][colors[u] - 'a']);
            for(int &v : adj[u])
            {
                for(int b = 0; b < 26; b++)
                {
                    t[v][b] = max(t[v][b], t[u][b] + (colors[v] - 'a' == b));
                }
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }
        if(cnt < n)
            return -1;
        return ans;
    }
};
