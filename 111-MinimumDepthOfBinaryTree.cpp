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
    int dfs(TreeNode* root){
        if(root==nullptr)
            return 0;
        if(root&&!root->left&&!root->right)
            return 1;
        else {
            int l = numeric_limits<int>::max();
            int r = numeric_limits<int>::max();
            if(root->left)
                l = dfs(root->left)+1;
            if(root->right)
                r = dfs(root->right)+1;
            return min(l, r);
        }
    }
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};
