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
    TreeNode* res = nullptr;
    void dfs(TreeNode* rt, TreeNode* p, bool& foundp){
        if(!rt) return;
        if(rt==p) {
            foundp = true;   
            return;
        }
        dfs(rt->left, p, foundp);
        if(foundp&&res==nullptr) res = rt;
        dfs(rt->right, p, foundp);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root||!p) return nullptr;
        if(p->right){
            auto start = p->right;
            while(start->left!=nullptr){
                start = start->left;
            }
            return start;
        }
        bool foundp = false;
        dfs(root, p, foundp);
        return res;
    }
};
