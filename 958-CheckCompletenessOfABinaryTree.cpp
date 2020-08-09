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
    bool checkLast(vector<TreeNode*> l){
        int i = 0;
        for(; i<l.size(); i++){
            if(!l[i]) break;
        }
        if(i==l.size()) return true;
        bool didIFindANonNullNodeLater = false;
        for(; !didIFindANonNullNodeLater&&i<l.size(); i++){
            if(l[i])didIFindANonNullNodeLater = true;
        }
        return !didIFindANonNullNodeLater;
    }
    bool checkIntermediate(vector<TreeNode*> l){
        int i = 0;
        for(; i<l.size(); i++){
            if(!l[i]) break;
        }
        if(i==l.size()) return true;
        else return false;
        //bool didIFindANonNullNodeLater = false;
        //for(auto it = fn; !didIFindANonNullNodeLater&&it!=l.end(); it++){
        //    if(!(*it))didIFindANonNullNodeLater = true;
        //    it++
        //}
        //return !didIFindANonNullNodeLater;
    }
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        vector<TreeNode*> ll;
        q.push(root);
        while(!q.empty()){
            ll.clear();
            while(!q.empty()){
                ll.push_back(q.front());
                q.pop();
            }
            bool foundNonNull = false;
            for(const auto& n : ll){
                if(n){
                    if(n->left) foundNonNull = true;
                    if(n->right) foundNonNull = true;
                    q.push(n->left);
                    q.push(n->right);
                }
            }
            if(!foundNonNull) q = queue<TreeNode*>();
            else if(!checkIntermediate(ll))
                    return false;
        }
        return checkLast(ll);
    }
};
