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
    void dfs(TreeNode* root, int curr){
        if(!root) return;
        if(curr==d-1){
            auto l = new TreeNode(v, root->left, nullptr);
            auto r = new TreeNode(v, nullptr, root->right);
            root->left = l;
            root->right = r;
            return;
        }
        dfs(root->left, curr+1);
        dfs(root->right, curr+1);
    }
    int d{};
    int v{};
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            if(root){
                auto n = new TreeNode(v, root, nullptr);
                return n;
            }
            return root;
        }
        this->d = d;
        this->v = v;
        dfs(root, 1);
        return root;
    }
};
