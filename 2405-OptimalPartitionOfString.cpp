class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> seen;
        int res = 1;
        for(const auto& c : s){
            if(seen.find(c)!=seen.end()){
                seen = unordered_set<char>();
                res++;
            }
            seen.insert(c);
        }
        return res;
    }
};
