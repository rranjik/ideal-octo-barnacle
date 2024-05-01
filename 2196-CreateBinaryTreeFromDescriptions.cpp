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
    void build(int v, TreeNode* h){
        if(r.find(v)!=r.end()){
            h->right = new TreeNode(r[v]);
            build(r[v], h->right);
        }
        if(l.find(v)!=l.end()){
            h->left = new TreeNode(l[v]);
            build(l[v], h->left);
        }
        return;
    }
    unordered_map<int, int> r;
    unordered_map<int, int> l;
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int, int> occ;
        unordered_set<int> un;
        for(const auto& d : des){
            if(d[2]==0){
                r[d[0]] = d[1];
            }else{
                l[d[0]] = d[1];
            }
            occ[d[1]]++;
            un.insert(d[0]);
        }
        int rootv = -1;
        for(const auto& it : un){
            if(occ.find(it)==occ.end()){
                rootv = it;
            }
        }
        if(rootv==-1) {
            cout<<"something is wrong "<<endl;
            return nullptr;
        }
        TreeNode* res = new TreeNode(rootv);
        build(rootv, res);
        return res;
    }
};
