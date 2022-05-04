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
    bool dfs(TreeNode* r, vector<int>& l){
        if(!r) return true;
        if(!r->left&&!r->right) {l.push_back(r->val); return true;}
        auto ll = dfs(r->left, l);
        auto rr = dfs(r->right, l);
        if(ll) r->left = nullptr;
        if(rr) r->right = nullptr;
        return false;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> l;
        while(!dfs(root, l)){
            res.push_back((l));
            l.clear();
        }
        l.clear();
        l.push_back(root->val);
        res.push_back(l);
        return res;
    }
};
