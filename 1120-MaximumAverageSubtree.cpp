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
    double dfs(TreeNode* root, int& rs, int& n){
        if(!root){
            return 0;
        }
        int rsl = 0;
        int rsr = 0;
        int nl = 0;
        int nr = 0;
        auto l = dfs(root->left, rsl, nl);
        auto r = dfs(root->right, rsr, nr);
        rs += (root->val+rsl+rsr);
        n+= (nl + nr + 1);
        double me = ((double)rs/(n));
        double res = max(me, max(l, r));
        cout<<root->val<<" says "<<res<<endl;
        return res;
    }
    double maximumAverageSubtree(TreeNode* root) {
        int rs = 0;
        int n = 0;
        return dfs(root, rs, n);
    }
};
