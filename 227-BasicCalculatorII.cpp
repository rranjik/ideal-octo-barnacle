class Solution {
public:
    unordered_map<char, int> p = {
        {'(', 0},
        {'+', 1},
        {'-', 1},
        {'/', 2},
        {'*', 2},
    };
    string remspace(string s){
        string res;
        for(const auto& c : s) if(c!=' ') res+=c;
        return res;
    }
    string remunary(string s){
        string res;
        for(int i = 0; i<s.size(); i++){
            if((i==0||s[i-1]=='(')&&(s[i]=='-'||s[i]=='+')){
                res+='0';
            }
            res+=s[i];
        }
        return res;
    }
    int calculate(string s) {
        s = "("+s+")";
        s = remspace (s); s = remunary(s);
        stack<int> nstk; 
        stack<char> opstk;
        int i = 0;
        while(i<s.size()){
            if(s[i]=='('){
                opstk.push(s[i]);
            }else if(s[i]>='0'&&s[i]<='9'){
                int x = 0;
                while(s[i]>='0'&&s[i]<='9'){
                    x=x*10+(s[i]-'0');
                    i++;
                }
                i--;
                nstk.push(x);
            }else{
                while((opstk.size())&&
                (opstk.top()!='(')&&
                (p[opstk.top()]>=p[s[i]])){
                    auto n2 = nstk.top(); nstk.pop();
                    auto n1 = nstk.top(); nstk.pop();
                    auto op = opstk.top(); opstk.pop();
                    auto x = eval(op, n1, n2);
                    nstk.push(x);
                }
                if(s[i]==')'){
                    opstk.pop();
                }else{
                    opstk.push(s[i]);
                }
            }
            i++;
        }
        return nstk.top();
    }
    int eval(char op, int n1, int n2){
        switch(op){
            case '+': return n1+n2;
            case '-': return n1-n2;
            case '/': return n1/n2;
            case '*': return n1*n2;
            default: return 0;
        }
        return 0;
    }
};
