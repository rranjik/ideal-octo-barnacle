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
    unordered_map<int, int> f;
    int dfs(TreeNode* r){
        if(!r) return 0;
        int sum{};
        sum+=dfs(r->left);
        sum+=dfs(r->right);
        sum+=r->val;
        f[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        int rr{};
        vector<int> res;
        for(const auto& it : f){
            if(it.second>rr){
                rr = it.second;
                res.clear();
                res.push_back(it.first);
            }else if(it.second==rr){
                res.push_back(it.first);
            }
        }
        return res;
    }
};
