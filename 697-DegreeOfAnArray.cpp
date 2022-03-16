
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, pair<int, int>> intvl;
        unordered_map<int, int> f;
        int d  = 0;
        for(int i = 0; i<nums.size(); i++){
            f[nums[i]]++;
            if(d<f[nums[i]])d = f[nums[i]];
            if(intvl.find(nums[i])!=intvl.end()){
                intvl[nums[i]].second = i;
            }else {
                intvl[nums[i]] = {i, i};
            }
        }
        int res = nums.size();
        for(const auto& it : intvl){
            if(f[it.first]==d){
                if(it.second.second-it.second.first+1<res){
                    res = it.second.second-it.second.first+1;
                }
            }
        }
        return res;
    }
};
