/*
 *Definition for a binary tree node.
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
    void dfs(TreeNode* root, int h){
        if(!root) return;
        mh = max(mh, h);
        lm[h] = root;
        if(root->left) {
            l[root] = root->left;
            p[root->left] = root;
        }
        if(root->right){
            r[root] = root->right;
            s[root->left] = root->right;
        }
        dfs(root->left, h+1);
    }
    int mh = 0;
    unordered_map<TreeNode*, TreeNode*> l;
    unordered_map<TreeNode*, TreeNode*> p;
    unordered_map<int, TreeNode*> lm;
    unordered_map<TreeNode*, TreeNode*> r;
    unordered_map<TreeNode*, TreeNode*> s;
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root) return root;
        dfs(root, 0);
        for(const auto& [p, left] : l){
            cout<<left->val<<"'s parent is "<<p->val<<endl;
        }
        for(const auto& [p, right] : r){
            cout<<right->val<<"'s parent is "<<p->val<<endl;
        }
        for(const auto& [left, right] : s){
            cout<<left->val<<"'s sibling is "<<right->val<<endl;
        }
        cout<<"max height is "<<mh<<endl;
        auto mhc = mh;
        auto rt = lm[mh];
        auto res = lm[mh];
        cout<<"res is "<<res->val<<endl;
        while(mh>=0){
            cout<<"rt is "<<rt->val<<"; mh is "<<mh<<endl;
            rt->left = nullptr;
            rt->right = nullptr;
            if(s.find(rt)!=s.end()){
                cout<<" has left "<<endl;
                rt->left = s[rt];
                cout<<rt->val<<"'s left is "<<s[rt]->val<<endl;
            }
            if(p.find(rt)!=p.end()){
                cout<<" has right "<<endl;
                rt->right = p[rt];
                cout<<rt->val<<"'s right is "<<p[rt]->val<<endl;
            }
            if(mh-1>=0){
                cout<<" updating rt"<<endl;
                rt = lm[mh-1];
            }
            mh--;
        }
        cout<<"here "<<endl;
        return res;
    }
};
