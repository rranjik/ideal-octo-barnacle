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
    map<int, map<int, vector<int>>> m;
    void dfs(int x, int y, TreeNode* r){
        if(!r) return;
        m[y][x].push_back(r->val);
        dfs(x+1, y-1, r->left);
        dfs(x+1, y+1, r->right);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(0, 0, root);
        vector<vector<int>> res;
        for(auto& [coll, rowm]: m){
            vector<int> col;
            for(auto& [row, nodes]: rowm){
                sort(nodes.begin(), nodes.end());
                col.insert(col.end(), nodes.begin(), nodes.end());
            }
            res.push_back(col);
        }
        return res;
    }
};
