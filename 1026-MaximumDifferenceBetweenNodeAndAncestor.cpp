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
    void dfs(TreeNode* root, multiset<int>& p, int& res){
        if(!root) return;
        if(p.size()){
            auto f = *(p.begin());
            auto l = *(prev((p.end())));
            res = max(res, abs(root->val - f));
            res = max(res, abs(root->val - l));
        }
        p.insert({root->val});
        dfs(root->left, p, res);
        dfs(root->right, p, res);
        p.erase(p.find(root->val));
    }
    int maxAncestorDiff(TreeNode* root) {
        multiset<int> p;
        int res = 0;
        dfs(root, p, res);
        return res;
    }
};
