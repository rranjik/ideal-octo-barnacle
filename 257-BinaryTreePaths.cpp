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
    void dfs(TreeNode* r, string c, set<string>& res){
        if((!r->left)&&(!r->right)) {
            if(c.size()){
                c+="->";
            }
            auto add = to_string(r->val);
            c+=add;
            res.insert(c);
            return;
        }
        if(c.size()){
            c+="->";
        }
        auto add = to_string(r->val);
        c+=add;
        if(r->left)
        dfs(r->left, c, res);
        if(r->right)
        dfs(r->right, c, res);
        //int i = 0;
        //while(i<add.length()+2) {i++; c.pop_back();}
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        set<string> res;
        string c;
        dfs(root, c, res);
        vector<string> rres(begin(res), end(res));
        return rres;
    }
};
