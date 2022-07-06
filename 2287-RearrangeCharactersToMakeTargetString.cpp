class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<int, int> m;
        for(const auto& c : s){
            m[c]++;
        }
        int l = 1e9;
        unordered_map<char, int> tc;
        for(const auto& t : target){
            tc[t]++;
        }
        for(const auto& [t, f] : tc){
            l = min(l, m[t]/f);
        }
        return l;
    }
};
