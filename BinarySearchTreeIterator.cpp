/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    int ptr = 0;
    vector<int> in;
    
    void inorder(TreeNode* root){
        if(root==nullptr)
            return;
        else{
            inorder(root->left);
            in.push_back(root->val);
            inorder(root->right);
        }
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        int temp = in[ptr];
        ptr++;
        return temp;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return ptr<in.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
