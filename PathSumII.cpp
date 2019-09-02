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
    int target;
    void dfs(TreeNode* root, int cs, vector<int> cp, vector<vector<int>>& res){
        if(root == nullptr){
            return;
        }
        if(root->left==nullptr&& root->right==nullptr){
            if(cs+root->val == target){
                cp.push_back(root->val);
                res.push_back(cp);
            }
            return;
        }
        else{
            cp.push_back(root->val);
            if(root->left) dfs(root->left, cs+root->val, cp, res);
            if(root->right) dfs(root->right, cs+root->val, cp, res);
            return;
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        target = sum;
        vector<vector<int>> res;
        dfs(root, 0, vector<int>(), res);
        return res;
    }
};
