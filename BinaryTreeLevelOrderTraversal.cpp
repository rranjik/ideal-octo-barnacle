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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr){
            return res;
        }
        else{
            queue<pair<int, TreeNode*>> q;
            q.push(pair<int, TreeNode*>(0, root));
            while(!q.empty()){
                auto p = q.front();
                q.pop();
                if(res.size()<= p.first){
                    vector<int> sq = vector<int> {p.second->val};
                    res.push_back(sq);
                }
                else{
                    res[p.first].push_back(p.second->val);
                }
                if(p.second->left!=nullptr){
                    q.push(pair<int, TreeNode*> (p.first+1, p.second->left));
                }
                if(p.second->right!=nullptr){
                    q.push(pair<int, TreeNode*> (p.first+1, p.second->right));
                }
            }
            return res;
        }
    }
};
