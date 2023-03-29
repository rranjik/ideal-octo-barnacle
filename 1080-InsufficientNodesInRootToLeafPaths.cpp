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
    //todelete
    unordered_set<TreeNode*> td;
    int dfs(TreeNode* n, int s){
        if(!n) return numeric_limits<int>::min();
        cout<<n->val<<" called with "<<s<<endl;
        int ls{numeric_limits<int>::min()};
        int rs{numeric_limits<int>::min()};
        if(!n->left&&!n->right) {
            cout<<n->val<<" returns "<<s+n->val<<endl;
            if(s+n->val<l) td.insert(n); 
            return s+n->val;
        }
        if(n->left)
        ls = dfs(n->left, s+n->val);
        if(n->right)
        rs  = dfs(n->right, s+n->val);
        cout<<n->val<<" ls = "<<ls<<"; rs = "<<rs<<endl;
        if(ls<l&&rs<l){
            td.insert(n);
        }
        auto res = max(ls, rs);
        cout<<n->val<<" returns "<<res<<endl;
        return res;
    }
    TreeNode* dfsd(TreeNode* n){
        if(!n) return nullptr;
        auto l = dfsd(n->left);
        auto r = dfsd(n->right);
        n->left = l;
        n->right = r;
        if(td.find(n)!=td.end()) return nullptr;
        return n;
    }
    int l;
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        l = limit;
        auto r = dfs(root, 0);
        if(r<l) td.insert(root);
        return dfsd(root);
    }
};
