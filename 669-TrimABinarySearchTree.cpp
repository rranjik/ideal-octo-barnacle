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
    bool withinLimits(int val){
        return (val>=L)&&(val<=R);
    }
    TreeNode* prune(TreeNode* r){
        if(!r) return nullptr;
        if(withinLimits(r->val)){
            r->left = prune(r->left);
            r->right = prune(r->right);
            return r;
        }else if(r->val<L){
            //r = nullptr;
            return prune(r->right);
        }else {
            //r = nullptr;
            return prune(r->left);
        } return nullptr;
    }
    int L;
    int R;
    TreeNode* trimBST(TreeNode* root, int l, int r) {
        L = l;
        R = r;
        if(!root) return nullptr;
        return prune(root);
    }
};
