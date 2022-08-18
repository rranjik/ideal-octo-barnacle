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
    int res{};
    map<int, int> dfs(TreeNode* root){
        if(!root) return {};
        
        if(!root->left&&!root->right){
            return {{1, 1}};
        }
        map<int, int> l;
        map<int, int> r;
        if(root->left){
            l = dfs(root->left);
        }
        if(root->right){
            r = dfs(root->right);
        }
        for(const auto& it : l){
            auto to = r.upper_bound(d-it.first);
            for(auto i = r.begin(); i!=to; i++){
                res+=((*i).second*it.second);
                //cout<<"at "<<root->val<<" adding "<<it.second*n<<endl;
            }
        }
        map<int, int> rr;
        for(const auto& it : l) rr[it.first+1] += it.second;
        for(const auto& it : r) rr[it.first+1] += it.second;
        //cout<<"at "<<root->val<<endl;
        //cout<<"returning "<<endl;
        //for(const auto& it : rr){
        //    cout<<"{"<<it.first<<"=>"<<it.second<<"} ";
        //}
        //cout<<endl;
        return rr;
    }
    int d;
    int countPairs(TreeNode* root, int distance) {
        d = distance;
        dfs(root);
        return res;
    }
};
