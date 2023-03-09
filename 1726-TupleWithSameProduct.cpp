class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i = 0; i<nums.size()-1; i++){
            for(int j = i+1; j<nums.size(); j++){
                m[nums[i]*nums[j]]++;
            }
        }
        int res{};
        for(const auto& it : m){
            if(it.second>=2){
                //cout<<"p = "<<it.first<<" np = "<<it.second<<endl;
                auto n = it.second;
                auto np = (n*(n-1))/2;
                res += np*8;
            }
        }
        return res;
    }
};
