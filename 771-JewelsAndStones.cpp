class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> j;
        for(const auto& c : J){
            j.insert(c);
        }
        int res= 0;
        for(const auto& s : S){
            if(j.find(s)!=j.end()) res++;
        }
        return res;
    }
};
