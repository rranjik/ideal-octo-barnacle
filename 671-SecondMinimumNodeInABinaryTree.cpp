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
        if(!root) return;
        s.insert(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    set<int> s;
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        if(s.size()<=1) return -1;
        return *(next(s.begin()));
    }
};
