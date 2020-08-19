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
    TreeNode* dfs(TreeNode* root, int x){
        if(!root) return nullptr;
        if(root->val == x) return root;
        auto l = dfs(root->left, x);
        if(l) return l;
        auto r = dfs(root->right, x);
        if(r) return r;
        return nullptr;
    }
    //number of nodes rooted at r
    void nnratr(TreeNode* root, int& res){
        if(!root) return;
        nnratr(root->left, res);
        nnratr(root->right, res);
        res++;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        auto red = dfs(root, x);
        cout<<red->val<<endl;
        //number of nodes rooted at r
        
        int nnratred = 0;
        nnratr(red, nnratred);
        cout<<"number of nodes root at red = "<<nnratred<<endl;
        
        //number of rooted to the left of red
        int nnratredl = 0;
        nnratr(red->left, nnratredl);
        int nnratredr = 0;
        nnratr(red->right, nnratredr);
        //number of other nodes (from red's parent)
        int non = n - nnratred;
        cout<<"choose left "<<nnratredl<<" vs "<<nnratred-nnratredl+non<<endl;
        cout<<"choose right "<<nnratredr<<" vs "<<(nnratred-nnratredr+non)<<endl;
        cout<<"choose parent "<<non<<" vs "<<nnratred<<endl;
        if((nnratredl>(nnratred-nnratredl+non))
           ||(nnratredr>(nnratred-nnratredr+non))
           ||(non>nnratred)) 
            return true;
        return false;
    }
};
