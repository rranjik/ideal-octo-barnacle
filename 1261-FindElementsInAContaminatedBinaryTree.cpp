/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    unordered_set<int> seen;
    void fill(TreeNode* root){
        if(root){
            if(root->left) {
                root->left->val = 2*root->val +1;
                seen.insert(root->left->val);
                fill(root->left);
            }
            if(root->right) {
                root->right->val = 2*root->val +2;
                seen.insert(root->right->val);
                fill(root->right);
            }
        }
    }
    FindElements(TreeNode* root) {
        if(root) root->val = 0;
        fill(root);
    }
    
    bool find(int target) {
        return seen.find(target)!=seen.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
