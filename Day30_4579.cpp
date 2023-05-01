class Solution {
public:
    vector<int> p1, p2;
 
    int findSet(int u, vector<int> &p) {
        if(u == p[u])
            return u;
        return p[u] = findSet(p[u], p);
    }
    int merge(int u, int v, vector<int> &p) {
        int pu = findSet(u, p);
        int pv = findSet(v, p);
        if(pu != pv) {
            p[pv] = pu;
            return 1;
        }
        return 0;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        p1 = vector<int> (n+10);
        p2 = vector<int> (n+10);
        for(int i=0; i<=n; i++)
            p1[i] = i;
        int ans = 0;
        for(int i=0; i<edges.size(); i++) {
            if(edges[i][0] == 3) {
                ans += merge(edges[i][1], edges[i][2], p1);
            }
        }
        for(int i=1; i<=n; i++) {
            p2[i] = p1[i];
        }
        for(int i=0; i<edges.size(); i++) {
            if(edges[i][0] == 1) {
                ans += merge(edges[i][1], edges[i][2], p1);
            }
        }
        for(int i=0; i<edges.size(); i++) {
            if(edges[i][0] == 2) {
                ans += merge(edges[i][1], edges[i][2], p2);
            }
        }
        int par1 = findSet(1, p1);
        for(int i=1; i<=n; i++) {
            if(findSet(i, p1) != par1)
                return -1;
        }
 
        par1 = findSet(1, p2);
        for(int i=1; i<=n; i++) {
            if(findSet(i, p2) != par1)
                return -1;
        }
 
        return edges.size() - ans;
    }
};
