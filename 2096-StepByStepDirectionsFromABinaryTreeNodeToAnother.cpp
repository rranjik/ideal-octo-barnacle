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
    bool find(TreeNode* r, int v, string& p){
        if(r->val==v) return true;
        auto res = false;
        if(r->left&&find(r->left, v, p)){
            res = true;
            p.push_back('L');
        }
        else if(r->right&&find(r->right, v, p)){
            res = true;
            p.push_back('R');
        }
        return res;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s, d;
        find(root, startValue, s);
        find(root, destValue, d);
        cout<<s<<" "<<d<<endl;
        while(!s.empty()&&!d.empty()&&s.back()==d.back()){
            s.pop_back();
            d.pop_back();
        }
        reverse(begin(d), end(d));
        return string(s.size(), 'U')+d;
    }
};
