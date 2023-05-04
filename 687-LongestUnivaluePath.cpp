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
    int res{};
    int dfs(TreeNode* root){
        if(!root) return 0;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int l = 0;
        int r = 0;
        if(root->left&&root->left->val==root->val){
            l+=(left+1);
        }
        if(root->right&&root->right->val==root->val){
            r+=(right+1);
        }
        //if root and root->left was not the same then
        //l would have been 0 and l+r would not be aff-
        //ected
        //|||ly for root->right and root if they were not
        //teh same then r would be zero
        //exampe, if all three were different the l+r would be
        //0 implying the longest using this is 0
        //res = max(res, l+r);
        res = max(res, l);
        res = max(res, r);
        if(root->left&&root->right&&root->left->val==root->val&&root->val==root->right->val){
            res = max(res, l+r);
        }
        //the one above uses the root and extends either to the left,
        //or the right, or both or none
        //this is longest either to the left or to the 
        //right so it can be exteneded by its parent
        return max(l, r);
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res;
    }
};
