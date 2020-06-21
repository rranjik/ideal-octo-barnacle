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
    void in(TreeNode* r, vector<int>& e){
        if(!r) return;
        in(r->left, e);
        e.push_back(r->val);
        in(r->right, e);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> f;
        in(root1, f);
        vector<int> s;
        in(root2, s);
        int i = 0; int j = 0;
        vector<int> res;
        while(i<f.size()|| j<s.size()){
            bool iwon = false;
            bool jwon = false;
            int a = numeric_limits<int>::max();
            if(i<f.size()){
                a = f[i];
            }
            int b = numeric_limits<int>::max();
            if(j<s.size()){
                b = s[j];
            }
            if(a<b){
                iwon = true;
                res.push_back(f[i]);
                i++;
            }else{
                jwon = true;
                res.push_back(s[j]);
                j++;
            }
        }
        return res;
    }
};
