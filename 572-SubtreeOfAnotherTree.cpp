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
    bool isIdentical(TreeNode* r, TreeNode* t){
        if(!t&&r) return false;
        if(!r&&t) return false;
        if(!r&&!t) return true;
        if(r->val==t->val) 
            return isIdentical(r->left, t->left) && isIdentical(r->right, t->right);
        else return false;
    }
    bool dfs(TreeNode* r, TreeNode* t){
        if(!r) return false;
        if(r->val==t->val){
            auto m = isIdentical(r->left, t->left) && isIdentical(r->right, t->right);
            if(m) return true;
        }
        return dfs(r->left, t) || dfs(r->right, t);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!t) return true;
        return dfs(s, t);
    }
};
