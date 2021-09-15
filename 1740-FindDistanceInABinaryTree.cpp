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
    unordered_map<TreeNode*, vector<TreeNode*>> adjl;
    TreeNode* pp;
    TreeNode* qq;
    int pv; int qv;
    void dfs(TreeNode* r){
        if(!r) return;
        if(r->val==pv) pp = r;
        if(r->val==qv) qq = r;
        if(r->left){
            adjl[r].push_back(r->left);
            adjl[r->left].push_back(r);
        }
        if(r->right){
            adjl[r].push_back(r->right);
            adjl[r->right].push_back(r);
        }
        dfs(r->left);
        dfs(r->right);
    }
    int findDistance(TreeNode* root, int P, int Q) {
        pv = P; qv = Q;
        dfs(root);
        queue<TreeNode*> q;
        q.push(pp);
        unordered_set<TreeNode*> v;
        v.insert(pp);
        int res = 0;
        cout<<"qq = "<<qq->val<<endl;
        cout<<"pp = "<<pp->val<<endl;
        while(!q.empty()){
            auto s = q.size();
            for(int i = 0; i<s; i++){
                auto f = q.front(); q.pop();
                cout<<"f = "<<f->val<<endl;
                if(f==qq) return res;
                for(const auto& cc : adjl[f]){
                    if(v.find(cc)==v.end()) {
                        v.insert(cc); q.push(cc);
                    }
                }
            }
            cout<<"res = "<<res<<endl;
            res++;
        }
        return res;
    }
};
