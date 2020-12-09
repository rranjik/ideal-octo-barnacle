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
    vector<int> n;
    void dfs(TreeNode* r){
        if(!r) return;
        dfs(r->left);
        n.push_back(r->val);
        dfs(r->right);
    }
    TreeNode* increasingBST(TreeNode* r) {
        dfs(r);
        for(const auto& r : n){
            cout<<r<<" ";
        }
        cout<<endl;
        TreeNode* root{nullptr};
        TreeNode* curr{nullptr};
        for(const auto& e : n){
            if(!curr){
                curr = new TreeNode(e);
                root = curr;
            }else{
                curr->right = new TreeNode(e);
                curr = curr->right;
            }
        }
        return root;
    }
};
