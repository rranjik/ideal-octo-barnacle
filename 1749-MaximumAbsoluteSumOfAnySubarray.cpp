class Solution {
public:
    int minSumSubArray(const vector<int>& v){
        int res{};
        int min_ending_here{};
        for(const auto& a : v){
            //previous elements cannot contribute to min 
            //if positive p - prev; h - here
            //p > 0 in this case
            //p + h > h if(h>0) or even if (h<0)
            //5 + 2 = 7 > 2; 5 + (-2) = 3 > -2
            //we are better off just choosing this
            if(min_ending_here>0){
                min_ending_here = a;
            }else{
                //else we could inclde the previous
                //p + h; p <= 0 in this case 
                //-5 + 3 = -2 < 3; -5 + (-3) = -8 < -3
                min_ending_here += a;
            }
            res = min(res, min_ending_here);
        }
        return res;
    }
    int maxSumSubArray(const vector<int>& v){
        int res{};
        int max_ending_here{};
        for(const auto& a : v){
            if(max_ending_here<0)
                max_ending_here = a;
            else
                max_ending_here += a;
            res = max(res, max_ending_here);
        }
        return res;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        return max(maxSumSubArray(nums), abs(minSumSubArray(nums)));
    }
};
