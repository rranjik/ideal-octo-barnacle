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
    int res = 0;
    tuple<bool, int, int> dfs(TreeNode* root, int& sum){
        if(!root) return {true, 1e9, -1e9};
        int lsum = 0; int rsum = 0;
        auto [ll, lmin, lmax] = dfs(root->left, lsum);
        auto [rr, rmin, rmax] = dfs(root->right, rsum);
        sum+=(root->val+lsum+rsum);
        if(ll&&rr){
            if(root->val>lmax&&root->val<rmin){
                res = max(res, lsum+rsum+root->val);
                cout<<"at "<<root->val<<" true sum = "<<sum<<endl;
                return {true, min(lmin, root->val), max(rmax, root->val)};
            }
        }
        cout<<"at "<<root->val
            <<" left = "<<(ll?"okay":"bad")
            <<" right = "<<(rr?"okay ":"bad ")
            <<"sum = "<<sum<<endl;
        return {false, 1e9, -1e9};
    }
    int maxSumBST(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return res;
    }
};
