/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int& res){
        if(!root) return 0;
        int l = dfs(root->left, res);
        int r = dfs(root->right, res);
        
        int included = root->val+l+r;
        
        res = max({res, included});
        
        return max(root->val+max(l, r), 0);
    }
    int maxPathSum(TreeNode* root) {
        int res = numeric_limits<int>::min();
        dfs(root, res);
        return res;
    }
};
