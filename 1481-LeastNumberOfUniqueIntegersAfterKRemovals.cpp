class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> f;
        for(const auto& a : arr) f[a]++;
        multimap<int, int> inv;
        for(const auto& it : f){
            inv.insert({it.second, it.first});
        }
        int res{};
        for(const auto& it : inv){
            if(k>=it.first){
                k-=it.first;
            }else{
                res++;
            }
        }
        return res;
    }
};
