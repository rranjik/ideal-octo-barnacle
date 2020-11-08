class Solution {
public:
    string decodeString(string s) {
        stack<int> count;
        stack<string> res_stack;
        int i = 0;
        string res;
        while(i<s.length()){
            if(isdigit(s[i])){
                int k = 0;
                while(isdigit(s[i])){
                    k = (k*10)+(s[i]-'0');
                    i++;
                }
                count.push(k);
            }else if(s[i]=='['){
                res_stack.push(res);
                res = "";
                i++;
            }else if(s[i] == ']'){
                int c = count.top();
                count.pop();
                string r = res_stack.top();
                res_stack.pop();
                while(c){
                    r+=res;
                    c--;
                }
                res = r;
                i++;
            }else{
                res+=s[i];
                i++;
            }
        }
        return res;
    }
};
