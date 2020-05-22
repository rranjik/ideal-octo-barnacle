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
    
    TreeNode* traverse(TreeNode* root, int& rs){
        if(!root) return root;
        //cout<<"root.val = "<< root->val<<" rs = "<<rs<<endl;
        traverse(root->right, rs);
        //cout<<"after right root.val = "<< root->val<<" rs = "<<rs<<endl;
        rs+= root->val;
        root->val = rs;
        //cout<<"after self root.val = "<< root->val<<" rs = "<<rs<<endl;
        traverse(root->left, rs);
        //cout<<"after left root.val = "<< root->val<<" rs = "<<rs<<endl;
        return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        int rs = 0;
        return traverse(root, rs);
    }
};
