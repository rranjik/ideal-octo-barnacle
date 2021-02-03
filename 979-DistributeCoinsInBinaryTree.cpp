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
    int dfs(TreeNode* r, int& res){
        if(!r) return 0;
        auto ll = dfs(r->left, res);
        auto rr = dfs(r->right, res);
        res+=(abs(ll)+abs(rr));
        return r->val+ll+rr-1;
    }
    int distributeCoins(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};
