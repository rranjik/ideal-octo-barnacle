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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        vector<TreeNode*> ll;
        while(!Q.empty()){
            ll = vector<TreeNode*>();
            while(!Q.empty()){
                auto t = Q.front();
                ll.push_back(t);
                Q.pop();
            }
            for(int i = 0; i<ll.size(); i++){
                if(ll[i]->left)
                    Q.push(ll[i]->left);
                if(ll[i]->right)
                    Q.push(ll[i]->right);
            }
        }
        auto res = 0;
        for(int i = 0; i<ll.size(); i++){
            res+=ll[i]->val;
        }
        return res;
    }
};
