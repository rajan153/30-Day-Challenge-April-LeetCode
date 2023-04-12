class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        for(int i = 0; i < path.size(); i++)
        {
            if(path[i] == '/')
                continue;
            string ans;  
            while(i < path.size() && path[i] != '/')
            {
                ans +=path[i];
                i++;
            }
            if(ans == ".")
                continue;
            else if(ans == "..")
            {
                if(!s.empty()){
                    s.pop();
                }
            }
            else
            {
                s.push(ans);
            }
        }
        string res;
        while(!s.empty())
        {
            res = "/" + s.top() + res;
            s.pop();
        }
        if(res.size() == 0)
            return "/";
        return res;
    }
};
