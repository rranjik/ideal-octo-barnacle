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
    using ull = unsigned long long int;
    int mod = 1e9+7;
    ull dfs(TreeNode* r, ull& res){
        if(!r) return 0;
        auto l = dfs(r->left, res);
        auto rr = dfs(r->right, res);
        int s = r->val+l+rr;
        auto c = t - s;
        res = max(res, (c*s));
        return s;
    }
    ull t = 0;
    int dfss(TreeNode* r){
        if(!r) return 0;
        int l = dfss(r->left);
        int rr = dfss(r->right);
        return r->val+l+rr;
    }
    int maxProduct(TreeNode* root) {
        t = dfss(root);
        ull res = 0;
        dfs(root, res);
        return res%mod;
    }
};
