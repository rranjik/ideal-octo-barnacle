class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, set<int, std::greater<int>>> res;
        vector<int> rres;
        map<int, int> f;
        for(const auto& n : nums){
            f[n]++;
        }
        for(const auto& it : f){
            res[it.second].insert(it.first);
        }
        for(const auto& it : res){
            auto l = it.second;
            for(const auto& n : l){
                for(int i = 0; i<it.first; i++)
                    rres.push_back(n);
            }
        }
        return rres;
    }
};
