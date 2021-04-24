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
    TreeNode* predecessor(TreeNode* n){
        n = n->left;
        while(n->right) n = n->right;
        return n;
    }
    TreeNode* successor(TreeNode* n){
        n = n->right;
        while(n->left) n = n->left;
        return n;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val>key){
            root->left = deleteNode(root->left, key);
        }else if(root->val<key){
            root->right = deleteNode(root->right, key);
        }else{
            if(!root->left&&!root->right) root=nullptr; 
            else if(root->left){
                auto p = predecessor(root);
                root->val = p->val;
                root->left = deleteNode(root->left,  root->val);
            }
            else{
                auto s = successor(root);
                root->val = s->val;
                root->right = deleteNode(root->right,  root->val);
            }
        }
        return root;
    }
};
