class Solution {
public:
    unordered_map<char, int> pred = {
        {')', -1},
        {'+', 0},
        {'-', 0},
        {'*', 1},
        {'/', 1},
    };
    string trim(string s){
        string res;
        for(int i = 0; i<s.size(); i++){
            if(s[i]!=' '){
                res+=s[i];
            }
        }
        return res;
    }
    string remunaryminus(string s){
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='-'&&!i){
                s = '0'+s;
            }
        }
        return s;
    }
    int calculate(string s) {
        s = trim(s);
        s = remunaryminus(s);
        s = "("+s+")";
        cout<<s<<endl;
        stack<char> opstack;
        stack<int> numstack;
        int i = 0;
        while(i<s.size()){
            auto c = s[i];
            if(c=='('){
                opstack.push(c);
                i++;
                continue;
            }
            if((c>='0')&&(c<='9')){
                int num = 0;               
                while(i<s.size()&&(s[i]>='0')&&(s[i]<='9')){
                    num = num*10+(s[i]-'0');
                    i++;
                }
                cout<<"num = "<<num<<endl;
                numstack.push(num);
            }else {
                cout<<c<<endl;
                while(!opstack.empty()&&opstack.top()!='('&&
                pred[c]<=pred[opstack.top()]){
                    auto n2 = numstack.top(); numstack.pop();
                    auto n1 = numstack.top(); numstack.pop();
                    auto op = opstack.top(); opstack.pop();
                    auto x = eval(op, n1, n2);
                    cout<<n1<<op<<n2<<" = "<<x<<endl;
                    numstack.push(x);
                }
                if(c==')'){
                    opstack.pop();
                }else{
                    cout<<"pushed "<<c<<endl;
                    opstack.push(c);
                }
                i++;
            }
        }
        return numstack.top();
    }
    int eval(char c, int n1, int n2){
        switch(c){
            case '+':
                return n1+n2;
            case '-':
                return n1-n2;
            case '/':
                return n1/n2;
            case '*':
                return n1*n2;
            default:
                return 0;
        }
        return 0;
    }
};
