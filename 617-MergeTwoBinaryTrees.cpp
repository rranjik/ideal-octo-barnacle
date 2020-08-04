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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* res;
        if(!t1&&!t2) res = nullptr;
        else if(t1&&t2) {
            res = new TreeNode(t1->val+t2->val);
            res->left = mergeTrees(t1->left, t2->left);
            res->right = mergeTrees(t1->right, t2->right);
        }else if(t1){
            res = new TreeNode(t1->val);
            res->left = t1->left;
            res->right = t1->right;
        }else{
            res = new TreeNode(t2->val);
            res->left = t2->left;
            res->right = t2->right;
        }
        return res;
    }
};
