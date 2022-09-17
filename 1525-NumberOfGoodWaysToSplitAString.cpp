class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int> l;
        unordered_map<char, int> r;
        for(const auto& c : s){
            r[c]++;
        }
        auto ru = r.size();
        int res{};
        for(int i = 0; i<s.size(); i++){
            auto c = s[i];
            r[c]--;
            if(!r[c]) ru--;
            l[c]++;
            auto lu = l.size();
            if(ru==lu) res++;
        }
        return res;
    }
};
