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
    TreeNode* search(TreeNode* root, TreeNode* parent, int v){
        if(!root) return parent;
        else if((root->val)>v){
            return search(root->left, root, v);
        }else return search(root->right, root, v);
    }
    TreeNode* insertIntoBST(TreeNode* root, int v) {
         TreeNode* p = search(root, nullptr, v);
         if(p){
             if(p->val>v){
                 p->left = new TreeNode(v);
             }else p->right = new TreeNode(v);
         }
        return root;
    }
};
