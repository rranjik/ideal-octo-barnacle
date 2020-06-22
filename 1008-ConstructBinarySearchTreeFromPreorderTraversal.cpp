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
    TreeNode* build(int i, int j, const vector<int>& p){
        cout<<"i = "<<i<<"; j = "<<j<<endl;
        if(i>j||(i<0)||(j>=p.size())) return nullptr;
        TreeNode* r = new TreeNode(p[i]);
        int mini = r->val;
        int k=i+1;
        for(; k<=j; k++){
            if(p[k]>mini) break;
        }
        r->left = build(i+1, k-1, p);
        r->right = build(k, j, p);
        return r;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(0, preorder.size()-1, preorder);
    }
};
