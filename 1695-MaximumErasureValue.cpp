class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> s;
        int i = 0; 
        int j = 0;
        int n = nums.size();
        int res = {};
        int lres{};
        while(j<n){
            //cout<<"j = "<<j<<" i = "<<i<<" res = "<<res<<endl;
            if(s.find(nums[j])==s.end()){
                s[nums[j]] = j;
                lres+=nums[j];
                res = max(lres, res);
            }else{
                //cout<<"found  "<<endl;
                res = max(lres, res);
                while(nums[i]!=nums[j]){
                    s.erase(nums[i]);
                    lres-=nums[i];
                    i++;
                }
                i++;
            }
            j++;
        }
        res = max(lres, res);
        return res;
    }
};
