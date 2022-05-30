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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<int> pred;
        stack<int> succ;
        
        t = target;
        
        inorder(root, pred);
        revinorder(root, succ);
        vector<int> res;
        while(k){
            if(pred.empty()){
                res.push_back(succ.top());
                succ.pop();
            }else if(succ.empty()){
                res.push_back(pred.top());
                pred.pop();
            }else if(abs(pred.top()-t)<abs(succ.top()-t)){
                res.push_back(pred.top());
                pred.pop();
            }else {
                res.push_back(succ.top());
                succ.pop();
            }
            k--;
        }
        return res;
    }
    double t;
    void inorder(TreeNode* r, stack<int>& s){
        if(!r) return;
        inorder(r->left, s);
        if(((double)r->val)>=t){
           //s.push(r->val);
           return;
        }
        s.push(r->val);
        inorder(r->right, s);
    }
    void revinorder(TreeNode* r, stack<int>& s){
        if(!r) return;
        revinorder(r->right, s);
        if(((double)r->val)<t){
           return;
        }
        s.push(r->val);
        revinorder(r->left, s);
    }
};
