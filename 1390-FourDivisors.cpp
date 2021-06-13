class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            if(m.find(nums[i])!=m.end()){
                res+=m[nums[i]];
            }else{
                int divisor = 1;
                int numDivisors = 0;
                for(int j = 2; j*j<=nums[i]; j++){
                    if(nums[i]%j==0){
                        divisor=j;
                        numDivisors++;
                    }
                }
                if(numDivisors==1&&divisor!=nums[i]/divisor){
                    m[nums[i]] = 1+divisor+nums[i]/divisor+nums[i];
                    res+=m[nums[i]];
                }else {
                    m[nums[i]] = 0;
                }
            }
        }
        return res;
    }
};
