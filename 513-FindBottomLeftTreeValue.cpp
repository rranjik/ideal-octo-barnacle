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
    void dfs(TreeNode* node, int curr, int& md, int& res){
        if(!node) return;
        if(curr>md){
            res = node->val;
            md = curr;
        }
        dfs(node->left, curr+1, md, res);
        dfs(node->right, curr+1, md, res);
    }
    int findBottomLeftValue(TreeNode* root) {
        int res{};
        int md = -1;
        dfs(root, 0, md, res);
        return res;
    }
};
