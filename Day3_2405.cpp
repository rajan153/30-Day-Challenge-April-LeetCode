int partitionString(string s) {
        //Using map
        map<char, int> m;
        int ans = 1;
        for(auto x : s)
        {
            if(m[x] > 0)
            {
                ans++;
                m.clear();
                m[x]++;
            }
            else
            {
                m[x]++;
            }
        }
        return ans;
    }
