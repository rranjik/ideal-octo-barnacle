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
    pair<int, int> dfs(TreeNode* r){
        if(!r) return {};
        auto [nl, sl] = dfs(r->left);
        auto [nr, sr] = dfs(r->right);
        if((sl+sr+r->val)/(nl+nr+1) == r->val) res++;
        return {nl+nr+1, sl+sr+r->val};
    }
    int res = 0;
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }
};
