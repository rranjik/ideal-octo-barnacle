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
    bool dfs(TreeNode* root){
        if(!root) return false;
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        if(!l) root->left = nullptr;
        if(!r) root->right = nullptr;
        if(l==false&&r==false&&root->val==0) return false;
        if((r||l)||root->val==1)return true;
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!dfs(root)) return nullptr;
        else return root;
    }
};
