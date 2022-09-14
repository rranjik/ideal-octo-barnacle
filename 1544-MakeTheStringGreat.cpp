class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        for(const auto& c : s){
            if(stk.empty()){
                stk.push(c);
            }else{
                auto t = stk.top();
                if(islower(t)){
                    if(toupper(t)==c){
                        stk.pop();
                    }
                    else{
                        stk.push(c);
                    }
                }
                if(!islower(t)){
                    if(!islower(t)&&tolower(t)==c){
                        stk.pop();
                    }else{
                        stk.push(c);
                    }
                }
            }
        }
        string res;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
