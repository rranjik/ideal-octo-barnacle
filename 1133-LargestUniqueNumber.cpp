class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        map<int, int, greater<int>> m;
        for(const auto& a : A){
            m[a]++;
        }
        for(auto it : m){
            if(it.second == 1) return it.first;
        }
        return -1;
    }
};
