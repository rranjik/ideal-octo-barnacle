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
    void dfs(TreeNode* root){
        if(root){
            if(!root->left&&!root->right){
                return;
            }
            if(!root->left||!root->right){
                if(!root->left) {
                    res.push_back(root->right->val);
                    dfs(root->right);
                }
                else if(!root->right) {
                    res.push_back(root->left->val);
                    dfs(root->left);
                }
            }else {
                dfs(root->left);
                dfs(root->right);
            }
        }
    }
    vector<int> res;
    vector<int> getLonelyNodes(TreeNode* root) {
        dfs(root);
        return res;
    }
};
