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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr){
            return res;
        }
        else{
            queue<pair<int, TreeNode*>> q;
            q.push(pair<int, TreeNode*>(1, root));
            while(!q.empty()){
                auto n = q.front();

                if(res.size()<n.first){
                    vector<int> l;
                    l.push_back(n.second->val);
                    res.push_back(l);
                }
                else{
                    res[n.first-1].push_back(n.second->val);
                }
                q.pop();
                if(n.second->left!=nullptr) q.push(pair<int, TreeNode*>(n.first+1, n.second->left));
                if(n.second->right!=nullptr) q.push(pair<int, TreeNode*>(n.first+1, n.second->right));
            }
            reverse(res.begin(), res.end());
            return res;
        }
    }
};
