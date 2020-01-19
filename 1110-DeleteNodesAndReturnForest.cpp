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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> td;//to delete
        for(const auto& v : to_delete){
            td.insert(v);
        }
        queue<TreeNode*> q;
        vector<TreeNode*> res;
        res.push_back(root);
        q.push(root);
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            if(td.find(cur->val)!=td.end()){
                res.erase(remove(res.begin(), res.end(), cur), res.end());
                if(cur->left) res.push_back(cur->left);
                if(cur->right) res.push_back(cur->right);
            }
            if(cur->left){
                q.push(cur->left);
                if(td.find(cur->left->val)!=td.end())
                    cur->left = nullptr;
            }
            if(cur->right){
                q.push(cur->right);
                if(td.find(cur->right->val)!=td.end())
                    cur->right = nullptr;
            }
        }
        return res;
    }
};
