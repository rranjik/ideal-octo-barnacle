class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        stack<char> stk;
        int start = 0;
        for(int i = 0; i<S.length(); i++){
            cout<<"size = "<<stk.size()<<endl;
            if(S[i]=='('){
                stk.push(S[i]);
            }else {
                stk.pop();
                if(stk.empty()){
                    cout<<"substr from "<<start+1
                        <<"; len = "<<i-start+1<<endl;
                    res+=(S.substr(start+1, (i-(start+1))));
                    start = i+1;
                }
            }
        }
        return res;
    }
};
