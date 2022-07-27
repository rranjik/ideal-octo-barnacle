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
    TreeNode* str2tree(string s) {
        s = "("+s+")";
        stack<TreeNode*> stk;
        int level{};
        TreeNode* res{};
        for(int i = 0, j = 0; i<s.length(); i++, j = i){
            if(s[i]==')'){
                level--;
                if(stk.size()>level) {
                    res = stk.top(), stk.pop();
                }
            }else if((s[i]>='0'&&s[i]<='9')||s[i]=='-'){
                while(i+1<s.length()&&s[i+1]>='0'&&s[i+1]<='9') i++;
                //cout<<"number is "<<s.substr(j, i-j+1)<<" level is "<<level<<endl;
                auto n = new TreeNode(stoi(s.substr(j, i-j+1)));
                if(!stk.empty()){
                    auto p = stk.top();
                    if(!p->left) p->left = n;
                    else p->right = n;
                }
                stk.push(n);
            }else{
                level++;
            }
        }
        cout<<"done! stk size is "<<stk.size()<<endl;
        return res;
        return stk.empty()?nullptr:stk.top();
    }
};
