/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, string& res, string curr){
        cout<<"curr = "<<curr<<" res = "<<res<<endl;
        if(!root){
            return;
        }
        char c = 'a'+root->val;
        curr+=string(1, c);
        if(!root->left&&!root->right){
            reverse(curr.begin(), curr.end());
            if(res>curr) {
                res = curr;
            }
            return;
        }
        dfs(root->left, res, curr);
        dfs(root->right, res, curr);
    }
    string smallestFromLeaf(TreeNode* root) {
        string res = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        string curr;
        dfs(root, res, curr);
        return res;
    }
};
