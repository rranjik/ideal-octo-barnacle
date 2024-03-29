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
    vector<int> nums;
    TreeNode* build(int l, int r){
        //cout<<"l = "<<l<<"; r = "<<r<<endl;
        if(l>r){
            return nullptr;
        }
        int m = (l+r)/2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = build(l, m-1);
        node->right = build(m+1, r);
        return node;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        this->nums = nums;
        return build(0, nums.size()-1);
    }
};
