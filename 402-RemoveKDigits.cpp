class Solution {
public:
    string removeKdigits(string num, int k) {
        //to add 
        int K = num.size()-k;
        if(!K) return "0";
        stack<int> stk;
        cout<<"to add "<<K<<endl;
        for(int i = 0; i<num.size(); i++){
            while(stk.size()+num.size()-i>K&&!stk.empty()&&stk.top()>((int)(num[i]-'0'))){
                stk.pop();
            }
            if(stk.size()<K) stk.push(num[i]-'0');
        }
        string res;
        while(stk.size()) {
            res+=string(1, (char)'0'+stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        int i = 0;
        while(res[i]=='0') i++;
        res = res.substr(i);
        if(!res.length()) return "0";
        return res;
    }
};
