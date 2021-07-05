class Solution {
public:
    map<char, int> precedence {
        {')', -1},
        {'+', 0},
        {'-', 0},
        {'*', 1},
        {'/', 1}
    };
    int calculate(string s) {
        if(!s.length()) return 0;
        stack<long> numstack;
        stack<char> opstack;
        string removespace;
        for(int i = 0; i<s.length();i++){
            if(s[i]!=' ') removespace+=string(1, s[i]);
        }
        //just rename for ease of use
        s = removespace;
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='-'&&(!i||(s[i-1]=='('))){
                s = s.substr(0, i)+"0"+s.substr(i);
            }
        }
        int i = 0;
        s = "("+s+")";
        cout<<"cleaned "<<s<<endl;
        while(i<s.length()){
            if(s[i]=='('){
                opstack.push('(');
                i++;
            }
            else if(s[i]>='0'&&s[i]<='9'){
                string n;
                while(i<s.length()&&(s[i]>='0'&&s[i]<='9')){
                    n+=string(1, s[i]);
                    i++;
                }
                numstack.push(stol(n));
            }
            else{
                while(!opstack.empty()&&opstack.top()!='('
                      &&(precedence[s[i]]<=precedence[opstack.top()])){
                    auto n2 = numstack.top();numstack.pop();
                    auto n1 = numstack.top();numstack.pop();
                    auto temp = op(n1, n2, opstack.top());
                    opstack.pop();
                    numstack.push(temp);
                }
                if(s[i]==')'){
                    opstack.pop();
                }else{
                    opstack.push(s[i]);
                }
                i++;
            }
        }
        return numstack.top();
    }
    long op(long n1, long n2, char oper){
        switch(oper){
            case '+':
                return n1+n2;
            case '-':
                return n1-n2;
            case '*':
                return n1*n2;
            case '/':
                return n1/n2;
        }
        return 0;
    }
};
