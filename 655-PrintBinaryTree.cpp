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
    int h{};
    void dfs(TreeNode* r, int ch){
        if(!r) return;
        h = max(ch, h);
        dfs(r->left, ch+1);
        dfs(r->right, ch+1);
    }
    void dfs2(TreeNode* r, int i, int s, int pos){
        if(!r) return;
        cout<<"val = "<<r->val<<" pos = "<<pos<<" s = "<<s<<endl;
        res[i][pos] = to_string(r->val);
        dfs2(r->left, i+1, s/2, pos-s/2);
        dfs2(r->right, i+1, s/2, pos+s/2);
    }
    vector<vector<string>> res;
    vector<vector<string>> printTree(TreeNode* root) {
        dfs(root, 1);
        auto c = pow(2, h)-1;
        cout<<"done dfs h = "<<h<<" c = "<<c<<endl;
        res = vector<vector<string>>(h, vector<string>(c));
        dfs2(root, 0, pow(2, h-1), c/2);
        return res;
    }
};
