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
    TreeNode* recoverFromPreorder(string s) {
        stack<TreeNode*> stk;
        for(int i = 0; i<s.length();){
            auto level = 0;
            for(;s[i]=='-';i++) level++;
            auto val = 0;
            for(;i<s.length()&&s[i]!='-'; i++) val = val*10+(s[i]-'0');
            while(stk.size()>level) stk.pop();
            auto node = new TreeNode(val);
            if(!stk.empty()){
                if(!stk.top()->left) stk.top()->left = node;
                else stk.top()->right = node;
            }
            stk.push(node);
        }
        while(stk.size()>1) stk.pop();
        return stk.top();
    }
};
