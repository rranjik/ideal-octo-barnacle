class Solution {
public:
    int minAddToMakeValid(string S) {
        int res = 0;
        stack<char> s;
        for(const auto& c : S){
            if(c=='('){
                s.push(c);
            }else{
                if(s.empty()) res++;
                else s.pop();
            }
        }
        res+=s.size();
        return res;
    }
};
