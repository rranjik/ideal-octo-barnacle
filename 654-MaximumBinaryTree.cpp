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
    TreeNode* build(int i, int j, const vector<int>& n){
        cout<<"i = "<<i<<"; j = "<<j<<endl;
        if(i>j/*||(i<0)||(j>=n.size())*/){return nullptr;}
        int maxi = numeric_limits<int>::min();
        int maxii= -1;
        for(int k = i; k<=j; k++){
            if(n[k]>maxi){
                maxi=n[k];
                maxii= k;
            }
        }
        TreeNode* r = new TreeNode(maxi);
        r->left = build(i, maxii-1, n);
        r->right = build(maxii+1, j, n);
        return r;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(0, nums.size()-1, nums);
    }
};
