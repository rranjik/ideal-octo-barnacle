class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;
        for(int i = 0; i<s.length(); i++){
            switch(s[i]){
                case ')':{
                    string r;
                    while(stk.top()!='('){
                        r+=stk.top();
                        stk.pop();
                    }
                    stk.pop();
                    for(const auto& c : r){
                        stk.push(c);
                    }
                }
                break;
                default:
                    stk.push(s[i]);
            }
        }
        string res;
        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }
        reverse(begin(res), end(res));
        return res;
    }
};
