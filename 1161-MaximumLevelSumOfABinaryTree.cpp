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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> ll;
        int ln = 0;
        int maxi = numeric_limits<int>::min();
        int maxl = -1;
        while(!q.empty()){
            ln++;
            ll.clear();
            while(!q.empty()){
                ll.push_back(q.front());
                q.pop();
            }
            int levelsum = 0;
            for(const auto& n : ll){
                levelsum += n->val;
            }
            if(levelsum>maxi){
                maxi = levelsum;
                maxl = ln;
            }
            for(const auto& n : ll){
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
        }
        return maxl;
    }
};
