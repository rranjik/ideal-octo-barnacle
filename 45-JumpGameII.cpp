class Solution {
public:
    int jump(vector<int>& nums) {
        int maximum_reach = 0;
        int end_of_element_i_reach = 0;
        int res = 0;
        for(int i = 0; i<nums.size()-1; i++){
            maximum_reach = max(maximum_reach, i+nums[i]);
            if(i==end_of_element_i_reach){
                res++;
                end_of_element_i_reach = maximum_reach;
            }
        }
        return res;
    }
};
