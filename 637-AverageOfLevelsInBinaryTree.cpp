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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        if(!root) return res;
        q.push(root);
        while(!q.empty()){
            auto len = q.size();
            double sum{};
            for(int i = 0; i<len; i++){
                auto n = q.front();
                sum+=n->val;
                q.pop();
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            res.push_back(sum/len);
        }
        return res;
    }
};
