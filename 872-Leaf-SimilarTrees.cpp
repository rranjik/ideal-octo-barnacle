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
    vector<int> t1;
    vector<int> t2;
    void dfs(TreeNode* r, vector<int>& res){
        if(!r) return;
        if(!r->left&&!r->right) {res.push_back(r->val); return;}
        dfs(r->left, res);
        //res.push_back(r->val);
        dfs(r->right, res);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, t1);
        dfs(root2, t2);
        for(const auto& v : t1){
            cout<<v<<" ";
        }
        cout<<endl;
        return t1==t2;
    }
};
