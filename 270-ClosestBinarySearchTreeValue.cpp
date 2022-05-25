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
    vector<int> in;
    void inorder(TreeNode* r){
        if(!r) return;
        inorder(r->left);
        cout<<"val = "<<r->val<<endl;
        if(r->val<t){
            ple = max(ple, (long long int) r->val);
            cout<<"update ple = "<<ple<<endl;
        }else {
            nge = min(nge,(long long int) r->val);
            cout<<"update nge = "<<nge<<endl;
        }
        inorder(r->right);
    }
    long long int ple = numeric_limits<long long int>::min();
    long long int nge = numeric_limits<long long int>::max();
    double t;
    int closestValue(TreeNode* root, double target) {
        t = target;
       inorder(root);
        cout<<"nge = "<<nge<<"; ple = "<<ple<<endl;
        auto dl = t-ple;
        auto dr = nge-t;
        if(dl>dr) return nge;
        return ple;
    }
};
