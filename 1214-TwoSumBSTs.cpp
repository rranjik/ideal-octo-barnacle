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
    unordered_set<int> s;
    void dfs(TreeNode* n){
        if(!n) return;
        s.insert(n->val);
        dfs(n->left);
        dfs(n->right);
    }
    bool dfsAgain(TreeNode* n){
        if(!n) return false;
        auto toFind = target-n->val;
        cout<<"looking for "<<toFind<<endl;
        if(s.find(toFind)!=s.end()) return true;
        return dfsAgain(n->left) || dfsAgain(n->right);
    }
    int target;
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        this->target = target;
        dfs(root1);
        return dfsAgain(root2);
    }
};
