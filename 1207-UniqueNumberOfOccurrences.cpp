class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> s;
        for(const auto& a :arr){
            ++s[a];
        }
        unordered_map<int, int> f;
        for(auto it :s){
            ++f[it.second];
            if(f[it.second]>1)
                return false;
        }
        return true;
    }
};
