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
    unordered_map<string, vector<TreeNode*>> m;
    string dfs(TreeNode* root){
        if(!root) return "null";
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        auto s = string("(")+to_string(root->val)+"("+l+")"+"("+r+")"+")";
        m[s].push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        vector<TreeNode*> res;
        for(auto& it : m){
            if(it.second.size()>1&&it.first!="null"){
                res.push_back(it.second[0]);
            }
        }
        return res;
    }
};
