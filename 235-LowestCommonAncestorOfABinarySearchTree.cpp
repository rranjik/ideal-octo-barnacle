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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root){
            if(p->val==root->val||q->val==root->val)
                return root;
            if ((root->val>p->val&&root->val<q->val) || (root->val>q->val&&root->val<p->val))
                return root;
            else {
                auto l = lowestCommonAncestor(root->left, p, q);
                auto r = lowestCommonAncestor(root->right, p, q);
                if(l&&r)
                    return root;
                return l ? l : r;
            }
        }
        else{
            return nullptr;
        }
    }
};
