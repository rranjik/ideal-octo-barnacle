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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> l;
        vector<int> res;
        while(!q.empty()){
            l.clear();
            int s = q.size();
            while(s){
                l.push_back(q.front());
                q.pop();
                s--;
            }
            int m = numeric_limits<int>::min();
            for(int i = 0; i<l.size(); i++){
                if(l[i]->left)
                    q.push(l[i]->left);
                if(l[i]->right)
                    q.push(l[i]->right);
                if(m<l[i]->val){
                    m = l[i]->val;
                }
            }
            res.push_back(m);
        }
        return res;
    }
};
