class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1;
        stack<char> s2;
        for(int i = 0; i<S.size(); i++){
            if(S[i]=='#'){
                if(!s1.empty()){
                    s1.pop();
                }
            }else {
                s1.push(S[i]);
            }
        }
        string s, t;
        while(!s1.empty()){
            s+=s1.top();
            s1.pop();
        }
        for(int i = 0; i<T.size(); i++){
            if(T[i]=='#'){
                if(!s2.empty()){
                    s2.pop();
                }
            }else {
                s2.push(T[i]);
            }
        }
        while(!s2.empty()){
            t+=s2.top();
            s2.pop();
        }
        cout<<"s = "<<s<<"; t = "<<t<<endl;
        return s == t;
    }
};
