class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int, greater<int>> f;
        for(const auto& a : arr) f[a]++;
        for(const auto& it : f){
            if(it.first==it.second) return it.first;
        }
        return -1;
    }
};
