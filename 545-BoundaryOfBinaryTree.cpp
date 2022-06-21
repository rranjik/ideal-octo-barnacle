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
    void dfs(TreeNode* rr){
        if(!rr) return;
        if(!rr->left&&!rr->right){
            if(m.find(rr)==m.end()){
                m.insert(rr);
                r.push_back(rr);
            }
            return;
        }
        dfs(rr->left);
        dfs(rr->right);
    }
    vector<TreeNode*> r;
    unordered_set<TreeNode*> m;
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        auto rr = root;
        while(rr){
            if(m.find(rr)==m.end()){
                r.push_back(rr);
                m.insert(rr);
            }
            if(rr!=root&&!rr->left)
                rr = rr->right;
            else rr=rr->left;
        }
        rr = root;
        dfs(root);
        vector<TreeNode*> rights;
        while(rr){
            if(m.find(rr)==m.end()){
                rights.push_back(rr);
                m.insert(rr);
            }
            if(rr!=root&&!rr->right)
                rr = rr->left;
            else rr=rr->right;
        }
        reverse(begin(rights), end(rights));
        r.insert(r.end(), begin(rights), end(rights));
        vector<int> res;
        for(const auto n : r){
            res.push_back(n->val);
        }
        return res;
    }
};
