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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            vector<TreeNode*> v;
            while(sz){
                auto f = q.front();
                q.pop();
                if(level%2){
                    v.push_back(f);
                }
                if(f->right){
                    q.push(f->left);
                    q.push(f->right);
                }
                sz--;
            }
            if(level%2){
                for(int i = 0, j = v.size()-1; i<v.size()/2; i++,j--){
                    auto t = v[j]->val;
                    v[j]->val = v[i]->val;
                    v[i]->val = t;
                }
            }
            level++;
        }
        return root;
    }
};
