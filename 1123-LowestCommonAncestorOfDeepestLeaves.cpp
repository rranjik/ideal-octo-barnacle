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
    unordered_set<TreeNode*> d;
    int m{};
    void dfs(TreeNode* r, int dd){
        if(!r) return;
        cout<<"@"<<r->val<<" dd = "<<dd<<endl;
        dfs(r->left, dd+1);
        dfs(r->right, dd+1);
        if(m<dd){
            m = dd;
            d.clear();
            d.insert(r);
        }else if(m==dd){
            d.insert(r);
        }
    }
    int t{};
    TreeNode* res{};
    bool done{};
    int sdfs(TreeNode* r, int& c){
        if(!r) return 0;
        int rres{};
        rres += sdfs(r->left, c);
        rres += sdfs(r->right, c);
        if(d.find(r)!=d.end()){
            rres+=1;
        }
        if(rres==d.size()&&!done){
           res = r;
           done = true;
        }
        cout<<"@ "<<r->val<<" c = "<<c<<endl;
        return rres;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 0);
        cout<<"done dd = "<<m<<endl;
        int c{}; 
        sdfs(root, c);
        return res;
    }
};
