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
    void dfs(TreeNode* r, TreeNode* p, TreeNode* gp, int& res){
        if(!r) return;
        if(gp){
            if(!(gp->val%2)) res+=r->val;
        }
        dfs(r->left, r, p, res);
        dfs(r->right, r, p, res);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int res = 0;
        dfs(root, nullptr, nullptr, res);
        return res;
    }
};
