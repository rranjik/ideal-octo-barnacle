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
    bool hps(TreeNode* root, int cs){
        if(root->left==nullptr&&root->right==nullptr){
            return ((cs+root->val) == target);
        }
        else{
            bool l = false, r= false;
            if(root->left) l = hps(root->left, cs+root->val);
            if(root->right) r = hps(root->right, cs+root->val);
            return (l||r);
        }
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr)
            return false;
        target = sum;
        return hps(root, 0);
    }
};
