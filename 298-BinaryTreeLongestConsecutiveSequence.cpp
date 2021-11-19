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
    int dfs(TreeNode* r, TreeNode* p, int l){
        if(!r) return l;
        l = (p&&p->val+1==r->val)?l+1:1;
        return max({l, dfs(r->left, r, l), dfs(r->right, r, l)});
    }
    int longestConsecutive(TreeNode* root) {
        return dfs(root, nullptr, 0);
    }
};
