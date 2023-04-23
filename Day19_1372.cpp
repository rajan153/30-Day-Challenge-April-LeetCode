class Solution {
public:
    int maxi = 0;
    void rec(TreeNode* root, int dir, int len)
    {
        if(root == NULL)    return;
        maxi = max(maxi,len);
        if(dir == 0)
        {
            rec(root->left, dir, 1);
            rec(root->right, dir^1, len+1);
        }
        else
        {
            rec(root->left, dir^1, len+1);
            rec(root->right, dir, 1);
        }
        return;
    }
    int longestZigZag(TreeNode* root, int val = 0) {
        rec(root->left,0,1);
        rec(root->right,1,1);
        return maxi;
    }
};
