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
    pair<int, int> dfs(TreeNode* root){
        if(!root) return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        auto through = l.first + r.first + 1;
        auto notthrough = max(l.second, r.second);
        return {max(l.first, r.first)+1, max(through, notthrough)};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        auto d = dfs(root);
        return max(d.first, d.second)-1;
    }
};
