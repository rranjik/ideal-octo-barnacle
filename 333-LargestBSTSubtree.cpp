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
    int minf = -10001;
    int pinf = 10001;
    vector<int> dfs(TreeNode* t){
        if(!t) {
            //eveything above you is valid
            //evruthing is smaller than positive infinity
            //evruthing is bigger than negative infinity
            return {pinf, minf, 0};
        }
        auto l = dfs(t->left);
        auto r = dfs(t->right);
        if(t->val>l[1]&&t->val<r[0]){
            //invalidating the extremes returnes on a null node
            //that why there's a min and max here
            //else this simply l[0] is min 
            //and r[1] is the max
            return {min(l[0], t->val), max(r[1], t->val), l[2]+r[2]+1};
            //return {l[0], r[1], l[2]+r[2]+1};
        }else{
            //anything above this cannot be valid
            //nothing is larger than positive infinity
            //nothing is smaller than  negative infinity
            //carry over answer
            return {minf, pinf, max(l[2], r[2])};
        }
    }
    int largestBSTSubtree(TreeNode* root) {
        auto v = dfs(root);
        return v[2];
    }
};
