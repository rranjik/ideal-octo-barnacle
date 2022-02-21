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
    bool dfs(TreeNode* r1, TreeNode* r2){
        if(!r1&&!r2) return true;
        else if(!r1&&r2) return false;
        else if(r1&&!r2) return false;
        else if(r1->val!=r2->val) return false;
        return (dfs(r1->left, r2->left)&&dfs(r1->right, r2->right))||
            (dfs(r1->left, r2->right)&&dfs(r1->right, r2->left));
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};
