class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p;
        vector<int> n;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>0){
                p.push_back(nums[i]);
            }else{
                n.push_back(nums[i]);
            }
        }
        vector<int> res;
        for(int i = 0; i<p.size(); i++){
            res.push_back(p[i]);
            res.push_back(n[i]);
        }
        return res;
    }
};
