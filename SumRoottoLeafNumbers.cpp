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
    long rs = 0;
    void dfs(TreeNode* n, string rn){
        if(n==nullptr)
            return;
        cout<<"n->val: "<<n->val<<"; rn: "<<rn<<endl;
        if(n->left==nullptr&&n->right==nullptr){
            rs+=(stol(rn+to_string(n->val)));
        }
        else{
            dfs(n->left, string(rn+to_string(n->val)));
            dfs(n->right, string(rn+to_string(n->val)));
        }
    }
    int sumNumbers(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        dfs(root, "");
        return rs;
    }
};
