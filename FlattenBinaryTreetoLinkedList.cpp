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
    TreeNode* fl(TreeNode* root){
        if(root==nullptr)
            return nullptr;
        else{
            auto left = fl(root->left);
            auto right = fl(root->right);
            root->left = nullptr;
            root->right = left;
            auto temp = root;
            while(temp->right!=nullptr)
                temp=temp->right;
            temp->right = right;
            return root;
        }
    }
    void flatten(TreeNode* root) {
        if(root==nullptr)
            return;
        fl(root);
    }
};
