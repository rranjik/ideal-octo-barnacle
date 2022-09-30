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
    vector<int> in;
    void dfs(TreeNode* r){
        if(!r) return;
        dfs(r->left);
        in.push_back(r->val);
        dfs(r->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        int res = numeric_limits<int>::max();
        for(int i = 0; i<in.size()-1; i++){
            res = min(res, in[i+1]-in[i]);
        }
        return res;
    }
};
