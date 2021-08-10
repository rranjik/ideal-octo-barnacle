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
    void dfs(TreeNode* root, int p, int& res){
        if(!root){
            return;
        }
        if((!root->left)&&(!root->right)){
            cout<<"adding "<<p<<" at val "<<root->val<<endl;
            int phere = (p*2)+root->val;
            res+=phere;
            return;
        }
        int phere = (p*2)+root->val;
        dfs(root->left, phere, res);
        dfs(root->right, phere, res);
    }
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        dfs(root, 0, res);
        return res;
    }
};
