class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int res = 0;
        for(const auto& w : words){
            if(w.size()>s.size()) {
                continue;
            }
            bool mismatch = false;
            for(int i = 0; i<w.size(); i++){
                if(w[i]!=s[i]) {
                    mismatch = true;
                    break;
                }
            }
            if(!mismatch) 
                res++;
        }
        return res;
    }
};
