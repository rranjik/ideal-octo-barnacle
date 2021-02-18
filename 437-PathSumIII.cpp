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
    void dfs(TreeNode* root, int& res, int rs, unordered_map<int, int>& m){
        if(!root) return;
        int sum = rs+root->val;
        int lookfor = sum - target;
        m[rs]++;
        if(m.find(lookfor)!=m.end())
            res+=m[lookfor];
        dfs(root->left, res, sum, m);
        dfs(root->right, res, sum, m);
        m[rs]--;
        if(!m[rs]) m.erase(m.find(rs));
    }
    int target;
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        target = sum;
        int res = 0;
        unordered_map<int, int> m;
        //m[0] = 1;
        int rs = 0;
        dfs(root, res, rs, m);
        return res;
    }
};
