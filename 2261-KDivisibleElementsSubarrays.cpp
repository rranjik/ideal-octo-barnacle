class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> s;
        vector<int> ps(nums.size()+1);
        ps[0] = 0;
        for(int i = 0; i<nums.size(); i++){
            ps[i+1] = ps[i]+(nums[i]%p==0?1:0);
        }
        //for(const auto& p : ps) cout<<p<<endl;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i; j<nums.size(); j++){
                auto d = ps[j+1]-ps[i];
                if(d>k) break;
                s.insert(vector<int>(nums.begin()+i, nums.begin()+j+1));
            }
        }
        return s.size();
    }
};
