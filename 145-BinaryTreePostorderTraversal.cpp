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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<int> s2;
        stack<TreeNode*> s1;
        if(!root) return res;
        s1.push(root);
        while(!s1.empty()){
            auto n = s1.top();
            s1.pop();
            s2.push(n->val);
            if(n->left){
                s1.push(n->left);
            }
            if(n->right){
                s1.push(n->right);
            }
        }
        while(!s2.empty()){
            res.push_back(s2.top());
            s2.pop();
        }
        return res;
    }
};
