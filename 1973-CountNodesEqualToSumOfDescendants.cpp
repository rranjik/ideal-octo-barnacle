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
    int res = 0;
    long long dfs(TreeNode* r){
        if(!r) return 0;
        auto ll = dfs(r->left);
        auto rr = dfs(r->right);
        if(ll+rr==r->val) res++;
        //cout<<"r = "<<r->val<<end;
        return ll+rr+r->val;
    }
    int equalToDescendants(TreeNode* root) {
        dfs(root);
        return res;
    }
};
