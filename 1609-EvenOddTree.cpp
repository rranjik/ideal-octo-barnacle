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
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        int level{};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            //cout<<"level = "<<level<<endl;
            auto s = q.size();
            auto n = q.front();
            auto l = n->val;
            //cout<<l<<" ";
            q.pop();
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
            if(level%2){
                if(l%2) return false;
            }else{
                if(!(l%2)) return false;
            }
            for(int i = 1; i<s; i++){
                if(level%2){
                    auto nn = q.front();
                    auto v = nn->val;
                    //cout<<v<<" ";
                    if(v%2) return false;
                    q.pop();
                    if(v>=l) return false;
                    l = v;
                    if(nn->left) q.push(nn->left);
                    if(nn->right) q.push(nn->right);
                }else{
                    auto nn = q.front();
                    auto v = nn->val;
                    //cout<<v<<" ";
                    if(!(v%2)) return false;
                    q.pop();
                    if(v<=l) return false;
                    l = v;
                    if(nn->left) q.push(nn->left);
                    if(nn->right) q.push(nn->right);
                }
            }
            //cout<<endl;
            level++;
        }
        return true;
    }
};
