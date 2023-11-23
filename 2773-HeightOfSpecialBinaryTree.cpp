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
    TreeNode* first;
    TreeNode* last;
    unordered_map<TreeNode*, bool> v;
    void ldfs(TreeNode* r){
        if(!r) return;
        cout<<"at "<<r->val<<endl;
        if(v[r]){
            last = r;
            first = r->left;
            if(last==first) {
                last->left = nullptr;
                last->right = nullptr;
                return;
            }
            while(last->left){
                auto lastl = last->left;
                last->left = nullptr;
                last->right = nullptr;
                last = lastl;
            }
            return;
        }
        v[r] = true;
        ldfs(r->left);
        ldfs(r->right);
        return;
    }
    int res = 0;
    void dfs(TreeNode* s, int h){
        res = max(res, h);
        if(!s) return;
        dfs(s->left, h+1);
        dfs(s->right, h+1);
    }
    int heightOfTree(TreeNode* root) {
        if(!root) return 0;
        ldfs(root);
        dfs(root, 0);
        return res-1;
    }
};
