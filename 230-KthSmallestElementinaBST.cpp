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
    vector<int> in;
    int inorder(TreeNode* root, int& k){
        if(root == nullptr)
            return -1;
        else{
            cout<<"k = "<<k<<endl;
            int l = inorder(root->left, k);
            if(k==0) return l;
            k--;
            if(k==0) return root->val;
            return inorder(root->right, k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};
