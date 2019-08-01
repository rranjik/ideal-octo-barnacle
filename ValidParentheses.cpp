class Solution {
public:
    stack<char> st;
    bool isValid(string s) {
        int c = 0;
        cout<<"s.length() is "<<s.length()<<endl;
        while(c<s.length()){
            cout<<"char is: "<<s[c]<<"; c is "<<c<<endl;
            switch(s[c]){
                case '(':{
                    cout<<"pushing "<<endl;
                    st.push('(');
                    c++;
                }
                break;
                case '[':{
                    st.push('[');
                    c++;
                }
                break;
                case '{':{
                    st.push('{');
                    c++;
                }
                break;
                case ')':{
                    if(st.empty()){
                        return false;
                    }
                    char t = st.top();
                    st.pop();
                    if(t!='(')
                        return false;
                    c++;
                }
                break;
                case '}':{
                    if(st.empty()){
                        return false;
                    }
                    char t = st.top();
                    st.pop();
                    if(t!='{')
                        return false;
                    c++;
                }
                break;
                case ']':{
                    if(st.empty()){
                        return false;
                    }
                    char t = st.top();
                    st.pop();
                    if(t!='[')
                        return false;
                    c++;
                }
                break;
            }
        }
        if(st.empty())
        return true;
        else return false;
    }
};
