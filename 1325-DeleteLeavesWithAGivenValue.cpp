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
    int t;
    bool dfs(TreeNode* root){
        if(!root){
            return true;
        }else if(!root->left&&!root->right&&root->val==t){
            return true;
        }else {
            auto l = dfs(root->left);
            auto r = dfs(root->right);
            if(l) root->left = nullptr;
            if(r) root->right = nullptr;
            if(l&&r&&root->val==t){
                return true;
            }
            else return false;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        t = target;
        if(dfs(root))return nullptr;
        else return root;
    }
};
