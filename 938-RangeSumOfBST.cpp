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
    int L;
    int R;
    void rangeSum(TreeNode* root, int& sum){
        if(root){
            //cout<<"root "<<root->val<<endl;
            if(root->val<L){
                //cout<<"too less, go right"<<endl;
                rangeSum(root->right, sum);
            }else if(root->val>R){
                //cout<<"too large, go left"<<endl;
                rangeSum(root->left, sum);
            }else{
                //cout<<"just right try both"<<endl;
                sum+=root->val;
                rangeSum(root->right, sum);
                rangeSum(root->left, sum);
            }
        }
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        this->L = L;
        this->R = R;
        int res = 0;
        rangeSum(root, res);
        return res;
    }
};
