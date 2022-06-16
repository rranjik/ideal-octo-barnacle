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
    int sum{0};
    int n = 0;
    void dfs(TreeNode* r){
        if(!r) return;
        sum+=r->val;
        n++;
        dfs(r->left);
        dfs(r->right);
    }
    
    int cut(TreeNode* r, TreeNode* p, bool& res){
        if(!r) return 0;
        auto s = 0;
        auto ll = cut(r->left, r, res);
        auto rr = cut(r->right, r, res);
        s+=r->val+ll+rr;
        if(p&&(sum-s==s)) res|=true;
        return s;
    }
    
    bool checkEqualTree(TreeNode* root) {
        dfs(root);
        if(!sum&&n==1) return false;
        if(sum%2) return false;
        bool res = false;
        cut(root, nullptr, res);
        return res;
    }
};
