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
    pair<bool, int> dfs(TreeNode* root, int& res){
        if(!root) return make_pair(true, -1);
        auto l = dfs(root->left, res);
        auto r = dfs(root->right, res);
        if(l.first&&r.first){
            if(l.second==-1&&r.second==-1){
                res++;
                return make_pair(true, root->val);
            }else if(l.second==-1){
                if(r.second == root->val){
                    res++;
                    return make_pair(true, root->val);
                }else{
                    return make_pair(false, root->val);
                }
            }else if(r.second == -1){
                if(l.second == root->val){
                    res++;
                    return make_pair(true, root->val);
                }else{
                    return make_pair(false, root->val);
                }
            }else if(l.second==r.second){
                if(root->val == l.second){
                    res++;
                    return make_pair(true, root->val);
                }else{
                    return make_pair(false, root->val);
                }
            }else return make_pair(false, root->val);
        }else return make_pair(false, root->val);
    }
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};
