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
    pair<bool, int> ib(TreeNode* root){
        if(root==nullptr)
            return pair<bool, int>(true, 0);
        else{
            auto l = ib(root->left);
            auto r = ib(root->right);
            if(abs(l.second-r.second)<=1){
                cout<<"returning true and height: "<<max(l.second, r.second)+1<<endl;
                return pair<bool, int>(true&&l.first&&r.first, max(l.second, r.second)+1);
            }
            else {
                cout<<"returning false and height: "<<max(l.second, r.second)+1<<endl;
                return pair<bool, int>(false, max(l.second, r.second)+1);
            }
        }
    }
    bool isBalanced(TreeNode* root) {
        return ib(root).first;
    }
};
