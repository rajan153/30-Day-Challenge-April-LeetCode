class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int size = q.size();
            int mmin = q.front().second;
            int first, last;
            for(int i=0; i<size; i++)
            {
                long long int curr = q.front().second-mmin;
                TreeNode* newNode = q.front().first;
                q.pop();
                if(i==0)
                    first = curr;
                if(i == size-1)
                    last = curr;
                if(newNode->left)
                    q.push({newNode->left, curr*2+1});
                if(newNode->right)
                    q.push({newNode->right, curr*2+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};
