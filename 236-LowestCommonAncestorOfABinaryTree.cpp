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
    TreeNode* p;
    TreeNode* q;
    TreeNode* rres;
    bool done = false;
    pair<bool, bool> dfs(TreeNode* rt){
        if(!rt) return {false, false};
        auto [fpl, fql] = dfs(rt->left);
        auto [fpr, fqr] = dfs(rt->right);
        auto res = make_pair<bool, bool>(false||fpl||fpr, false||fql||fqr);
        if(rt==p) res.first = true;
        if(rt==q) res.second = true;
        if(res.first&&res.second&&!done){
            done = true;
            rres = rt;
        }
        return res;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        dfs(root);
        return rres;
    }
};
