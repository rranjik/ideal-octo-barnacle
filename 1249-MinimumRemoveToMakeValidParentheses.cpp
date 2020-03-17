class Solution {
public:
    using pi = pair<char, int>;
    string minRemoveToMakeValid(string str) {
        stack<pi> s;
        for(int i = 0; i<str.length(); i++){
            switch (str[i]){
                case '(':
                    s.push(make_pair(str[i], i));
                    break;
                case ')':
                    if(s.empty()){
                        s.push(make_pair(str[i], i));
                    } else {
                        if(s.top().first=='('){
                            s.pop();
                        }else {
                            s.push(make_pair(str[i], i));
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        if(s.empty()){
            return str;
        } else {
            string res = str;
            while(!s.empty()){
                auto tmp = res;
                tmp.erase(s.top().second, 1);
                s.pop();
                res = tmp;
            }
            return res;
        }
        return "";
    }
};
