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
    pair<bool, int> dfs(TreeNode* root){
        if(!root) return make_pair(true, -1);
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        if(l.first&&r.first){
            if(l.second==-1&&r.second==-1){
                return make_pair(true, root->val);
            }else if(r.second==-1){
                if(root->val==l.second){
                    return make_pair(true, root->val);
                }
            }else if(l.second==-1){
                if(root->val==r.second){
                    return make_pair(true, root->val);
                }
            }else if(l.second==r.second){
                if(root->val==l.second){
                    return make_pair(true, root->val);
                }
            }
        }
        return make_pair(false, root->val);
    }
    bool isUnivalTree(TreeNode* root) {
        return dfs(root).first;
    }
};
