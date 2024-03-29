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
    bool checkSymmetry(TreeNode* n1, TreeNode* n2){
        if(!n1&&!n2)
            return true;
        if((n1&&!n2)||(!n1&&n2)||(n1->val!=n2->val))
            return false;
        return checkSymmetry(n1->left, n2->right)&&checkSymmetry(n1->right, n2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return checkSymmetry(root->left, root->right);
    }
};
