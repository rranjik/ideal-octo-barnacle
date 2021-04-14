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
    void dfs(TreeNode* root, int& s){
        if(!root) return;
        dfs(root->right, s);
        auto v = root->val;
        root->val +=s;
        s+=v;
        dfs(root->left, s);
    }
    TreeNode* convertBST(TreeNode* root) {
        int s = 0;
        dfs(root, s);
        return root;
    }
};
