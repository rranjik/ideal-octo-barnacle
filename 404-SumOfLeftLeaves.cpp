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
    bool dfs(TreeNode* root, int& res){
        if(!root) return false;
        if(!root->left&&!root->right) return true;
        auto l = dfs(root->left, res);
        if(l) res+=root->left->val;
        dfs(root->right, res);
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        
        return res;
    }
};
