class Solution {
public:
  // Withot Stack
    string removeStars(string s) {
        int j = 0;
        for(int i=0; i < s.size(); i++)
        {
            if(s[i] == '*')
                j--;
            else
            {
                s[j] = s[i];
                j++;
            }
        }
        return s.substr(0, j);
    }
};

// With Stack
class Solution {
public:
    string removeStars(string s) {
        stack<char> ch;
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            if(s[i] == '*')
                ch.pop();
            else
            {
                ch.push(s[i]);
            }
        }
        string ans;
        while(!ch.empty())
        {
            ans += ch.top();
            ch.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
