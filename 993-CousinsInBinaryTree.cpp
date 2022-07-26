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
    TreeNode* xp;
    TreeNode* yp;
    int xd{};
    int yd{};
    void dfs(TreeNode* root, TreeNode* parent, int d){
        if(!root) return;
        if(root->val==x) {
            xd = d;
            xp = parent;
        }
        if(root->val==y) {
            yp = parent;
            yd = d;
        }
        dfs(root->left, root, d+1);
        dfs(root->right, root, d+1);
    }
    int x;
    int y;
    bool isCousins(TreeNode* root, int x, int y) {
        this->x = x;
        this->y = y;
        dfs(root, nullptr, 0);
        return (xd==yd)&&(xp!=yp);
    }
};
