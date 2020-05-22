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
    //rs - running sum 
    TreeNode* traverse(TreeNode* root, int& rs){
        if(!root) return root;
        //cout<<"root.val = "<< root->val<<" rs = "<<rs<<endl;
	//everything to right is greater than root
	//so add them first
        traverse(root->right, rs);
        //cout<<"after right root.val = "<< root->val<<" rs = "<<rs<<endl;
	//include this node, too
        rs+= root->val;
        root->val = rs;
        //cout<<"after self root.val = "<< root->val<<" rs = "<<rs<<endl;
	//everything in the parent, and to the right of the parent will
	//be greater, and we can go left now
        traverse(root->left, rs);
        //cout<<"after left root.val = "<< root->val<<" rs = "<<rs<<endl;
        return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        int rs = 0;
        return traverse(root, rs);
    }
};
