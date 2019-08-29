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
    vector<int> preorder;
    vector<int> inorder;
    TreeNode* bT(int pl, int pr, int il, int ir) {
        cout<<"pl = "<<pl<<"; pr = "<<pr<<"; il = "<<il<<"; ir = "<<ir<<endl;
        if(pl>pr||il>ir){
            return nullptr;
        }
        else{
            cout<<"preorder[pl] = "<<preorder[pl]<<endl;
            size_t index = distance(inorder.begin(), find(inorder.begin(), inorder.end(), preorder[pl]));
            cout<<"index = "<<index<<endl;
            TreeNode* node = new TreeNode(preorder[pl]);
            node->left = bT(pl+1, pl+index-il, il, index-1);
            node->right = bT(pl+index-il+1, pr, index+1, ir);
            return node;
        }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        return bT(0, preorder.size()-1, 0, inorder.size()-1);
    }
};
