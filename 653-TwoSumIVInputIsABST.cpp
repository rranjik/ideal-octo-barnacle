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
    unordered_map<int, int> s;
    void dfs(TreeNode* r){
        if(!r) return;
        s[r->val]++;
        dfs(r->left);
        dfs(r->right);
    }
    bool res{};
    void find(TreeNode* r){
        if(res) return;
        if(!r) return;
        int v = r->val;
        //v+x=t
        //x=t-v
        auto tofind = t-v;
        if(s.find(tofind)!=s.end()){
            if(tofind!=v){
                res = true;  
                return;
            }else if(s[tofind]>1){
                res = true;
                return;
            }
        } 
        find(r->left);
        find(r->right);
    }
    int t{};
    bool findTarget(TreeNode* root, int k) {
        this->t = k;
        dfs(root);
        find(root);
        return res;
    }
};
