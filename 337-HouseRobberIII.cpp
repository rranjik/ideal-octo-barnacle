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
    map<pair<TreeNode*, bool>, int> c;
    int steal(TreeNode* root, bool stolen){
        auto coor = pair<TreeNode*, bool>{root, stolen};
        if(c.find(coor)!=c.end()){
            return c[coor];
        }
        int res = 0;
        if(!root) {
            c[coor] = 0;
            return c[coor];
        }
        //cout<<"at : "<<root->val<<" stolen : "<<stolen<<endl;
        if(!stolen){
            c[coor] = max((steal(root->left, true)+
                       steal(root->right, true) + root->val),
                       (steal(root->left, false) + 
                        steal(root->right, false)));
        }
        else{
            c[coor] = steal(root->left, false) + 
                        steal(root->right, false);
        }
        return c[coor];
    }
    int rob(TreeNode* root) {
        return steal(root, false);
    }
};
