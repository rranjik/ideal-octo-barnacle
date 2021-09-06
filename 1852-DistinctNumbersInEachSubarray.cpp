class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        unordered_set<int> s;
        unordered_map<int, int> f;
        while(r-l+1<=k){
            s.insert(nums[r]);
            f[nums[r]]++;
            r++;
        }
        //cout<<"l = "<<l<<" r = "<<r<<endl;
        vector<int> res;
        while(r<nums.size()){
            res.push_back(s.size());
            //cout<<"removing "<<nums[l]<<endl;
            f[nums[l]]--;
            if(!f[nums[l]]){
                s.erase(s.find(nums[l]));
            }
            l++;
            //cout<<"adding "<<nums[r]<<endl;
            s.insert(nums[r]);
            f[nums[r]]++;
            r++;
            //cout<<"l = "<<l<<" r = "<<r<<endl;
        }
        res.push_back(s.size());
        return res;
    }
};
