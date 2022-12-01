class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int res = 0;
        int mh = 0;
        int curr = 0;
        
        for(const auto& c : s){
            if(c=='('){
                curr++;
                mh = max(mh, curr);
            }else if(c==')'){
                curr--;
                if(!curr){
                    res = max(res, mh);
                    mh = 0;
                }
            }
        }
        return res;
    }
};
