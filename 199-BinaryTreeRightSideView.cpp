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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto sz = q.size();
            int last = -1;
            for(int i = 0; i<sz; i++){
                auto f = q.front(); q.pop();
                if(!f) continue;
                last = f->val;
                q.push(f->left);
                q.push(f->right);
            }
            res.push_back(last);
        }
        res.pop_back();
        return res;
    }
};
