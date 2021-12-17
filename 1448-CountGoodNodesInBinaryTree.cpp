/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int& res, int m){
        if(!root) return;
        if(root->val>=m) res++;
        dfs(root->left, res, max(m, root->val));
        dfs(root->right, res, max(m, root->val));
    }
    int goodNodes(TreeNode* root) {
        int res{};
        int m = numeric_limits<int>::min();
        dfs(root, res, m);
        return res;
    }
};
