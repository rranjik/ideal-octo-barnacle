class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for(int i = 0; i<s.length(); i++){
            auto c = s[i];
            while(!stk.empty()&&stk.top()==c){
                stk.pop();
                if(!stk.empty()){
                    c = stk.top();
                    stk.pop();
                }else c = ' ';
            }
            if(c!=' ') stk.push(c);
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
