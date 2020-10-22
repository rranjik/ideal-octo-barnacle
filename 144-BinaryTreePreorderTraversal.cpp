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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        if(!root) return res;
        s.push(root);
        while(!s.empty()){
            auto n = s.top();
            s.pop();
            res.push_back(n->val);
            if(n->right) s.push(n->right);
            if(n->left) s.push(n->left);
        }
        return res;
    }
};
