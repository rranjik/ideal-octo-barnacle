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
    int res{0};
    auto dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        auto sum = 0;
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        sum+=root->val+l+r;
        res+=abs(l-r);
        return sum;
    }
    int findTilt(TreeNode* root) {
        dfs(root);
        return res;
    }
};
