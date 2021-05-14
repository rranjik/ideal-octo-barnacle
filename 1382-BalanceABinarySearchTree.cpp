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
    vector<int> inorder;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }
    TreeNode* ctor(int i, int j){
        if(j<i) return nullptr;
        if(i==j) return new TreeNode(inorder[i]);
        auto m = i + (j-i)/2;
        auto root = new TreeNode(inorder[m]);
        root->left = ctor(i, m-1);
        root->right = ctor(m+1, j);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return ctor(0, inorder.size()-1);
    }
};
