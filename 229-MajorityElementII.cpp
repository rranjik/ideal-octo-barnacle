class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int a = -20;
        int b = -20;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i<nums.size(); i++){
            int c = nums[i];
            if(a == c)
                count1++;
            else if(b==c)
                count2++;
            else if(count1 == 0){
                count1=1;
                a = c;
            }
            else if(count2 == 0){
                count2=1;
                b = c;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for(const auto& n : nums){
            if(a == n) count1++;
            else if(b == n) count2++;
        }
        if(count1>nums.size()/3) 
            res.push_back(a);
        if(count2>nums.size()/3) 
            res.push_back(b);
        return res;
    }
};
