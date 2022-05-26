class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for(const auto& p : patterns){
            if(word.find(p)!=string::npos) res++;
        }
        return res;
    }
};
