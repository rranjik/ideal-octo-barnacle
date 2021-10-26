class Solution {
public:
    bool doess1breaks2(string s1, string s2){
        sort(begin(s1), end(s1));
        map<char, int> f;
        for(const auto& c : s2) f[c]++;
        for(const auto& c : s1){
            auto it = f.lower_bound(c);
            if(it!=f.end()){
                it->second--;
                if(!it->second){
                    f.erase(it);
                }
            }else return false;
        }
        return true;
    }
    bool checkIfCanBreak(string s1, string s2) {
        if(doess1breaks2(s1, s2)||doess1breaks2(s2, s1)) return true;
        return false;
    }
};
