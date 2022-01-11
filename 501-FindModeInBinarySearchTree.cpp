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
    unordered_map<int, int> m;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        m[root->val]++;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        vector<int> res;
        int maxx{};
        for(const auto& it : m){
            if(it.second>maxx){
                maxx = it.second;
                res = vector<int>();
                res.push_back(it.first);
            }else if(maxx==it.second){
                res.push_back(it.first);
            }
        }
        return res;
    }
};
