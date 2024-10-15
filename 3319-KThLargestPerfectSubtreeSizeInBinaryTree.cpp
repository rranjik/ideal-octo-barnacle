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
    vector<int> sz;
    pair<bool, int> dfs(TreeNode* r){
        if(!r) return {true, 0};
        auto [leftp, leftn] = dfs(r->left);
        auto [rightp, rightn] = dfs(r->right);
        bool thisp = leftp&&rightp&&(leftn==rightn);
        int thisn = leftn+rightn+1;
        if(thisp) sz.push_back(thisn);
        cout<<r->val<<" says "<<(thisp?"perfect":"imperfect")<<" "<<thisn<<endl;
        return {thisp, thisn};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);
        sort(sz.begin(), sz.end());
        reverse(sz.begin(), sz.end());
        for(const auto& x : sz) cout<<x<<" "; cout<<endl;
        return sz.size()>=k?sz[k-1]:-1;
    }
};
