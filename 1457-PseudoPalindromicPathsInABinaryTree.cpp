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
    bool isPal(const vector<int>& digits){
        int nodds{};
        for(int i = 0; i<10; i++){
            if(digits[i]%2) nodds++;
        }
        return nodds<=1;
    }
    void dfs(TreeNode* root, vector<int>& digits, int& res){
        if(!root){
            return;
        }
        if(!root->left&&!root->right){
            digits[root->val]++;
            if(isPal(digits)) res++;
            digits[root->val]--;
            return;
        }
        digits[root->val]++;
        dfs(root->left, digits, res);
        dfs(root->right, digits, res);
        digits[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int res{};
        vector<int> digits(10, 0);
        dfs(root, digits, res);
        return res;
    }
};
