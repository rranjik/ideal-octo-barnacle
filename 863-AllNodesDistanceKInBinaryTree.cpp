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
    unordered_map<TreeNode*, TreeNode*> parent;
    void dfs(TreeNode* r, TreeNode* p){
        if(!r) return;
        parent[r] = p;
        dfs(r->left, r);
        dfs(r->right, r);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root, nullptr);
        for(auto it : parent){
            if(parent[it.first]){
            cout<<it.first->val<<"'s parent is "<<
                parent[it.first]->val<<endl;
            }
        }
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, int> d;
        unordered_map<TreeNode*, bool> v;
        d[target] = 0;
        while(!q.empty()){
            auto n = q.front();
            q.pop();
            if(n){
                v[n] = true;
                cout<<"examining "<<n->val<<endl;
                if(!v[parent[n]]) {
                    q.push(parent[n]);
                    d[parent[n]] = d[n]+1;
                    //adding this takes the run time from 14% to 75%
                    //if(d[n]+1>K) break;
                }
                if(n->left) {
                    if(!v[n->left]){ 
                        q.push(n->left);
                        d[n->left] = d[n]+1;
                        //adding this takes the run time from 14% to 75%
                        //if(d[n]+1>K) break;
                    }
                }
                if(n->right) {
                    if(!v[n->right]){ 
                        q.push(n->right);
                        d[n->right] = d[n]+1;
                        //adding this takes the run time from 14% to 75%
                        //if(d[n]+1>K) break;
                    }
                }
            }
        }
        //adding this takes the run time from 14% to 75%
        //what's this doing anyway ?
        //in BFS we will never a find a node at distance k after we hit a 
        //node at distance k+1 because we always explore in order of 
        //increasing distances - a simple early exit mechanism
        vector<int> res;
        for(auto it : d){
            if(it.second == K&&it.first){
                res.push_back(it.first->val);
            }
        }
        return res;
    }
};
