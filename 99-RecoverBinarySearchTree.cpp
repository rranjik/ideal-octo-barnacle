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
    TreeNode* f = nullptr;
    TreeNode* s = nullptr;
    TreeNode* th = nullptr;
    
    void inorder(TreeNode* root, vector<TreeNode*>& in){
        if(root){
            inorder(root->left, in);
            //cout<<"inoderin "<<root->val<<endl;
            in.push_back(root);
            inorder(root->right, in);
        }
    }
    
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> in;
        inorder(root, in);
        int o = 0, t = 1;
        while(t<in.size()){
            cout<<in[o]->val<<endl;
            if(in[o]->val>in[t]->val){
                if(!f){
                    f = in[o];
                    s = in[t];
                    //cout<<"f is "<<f->val<<" s is "<<s->val<<endl;
                }
                else{
                    th = in[t];
                    //cout<<"th is "<<th->val<<endl;
                }
            }
            o++;
            t++;
        }
        if(th){
            auto temp = th->val;
            th->val = f->val;
            f->val =temp;
        }
        else{
            auto temp = f->val;
            f->val = s->val;
            s->val =temp;
        }
    }
};
