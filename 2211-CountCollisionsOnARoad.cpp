class Solution {
public:
    int countCollisions(string directions) {
        stack<char> stk;
        int res = 0;
        for(const auto& c : directions){
            if(stk.empty()){
                stk.push(c);
                continue;
            }
            if(c=='L'){
                auto t = stk.top();
                stk.pop();
                if(t=='L'){
                    stk.push('L');
                    stk.push('L');
                }else{
                    stk.push('S');
                    res += (t=='R'?2:1);
                }
            }else if(c=='S'){
                auto t = '0';
                if(stk.top()=='R'){
                    t = stk.top();
                    stk.pop();
                }
                stk.push('S');
                res += (t=='R'?1:0);
            }else {
                stk.push('R');
            }
        }
        bool found = false;
        while(!stk.empty()&&stk.top()=='R'){
            stk.pop();
        }
        while(!stk.empty()&&stk.top()=='S'){
            found = true;
            stk.pop();
        }
        cout<<"found = "<<(found?"yes":"no")<<endl;
        while(found&&!stk.empty()){
            if(stk.top()=='R') res++;
            stk.pop();
        }
        return res;
    }
};
