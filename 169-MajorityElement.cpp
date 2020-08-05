class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count{0};
        int elem{-1};
        for(const auto& n : nums){
            if(elem!=n){
                if(count) count--;
                else {
                    elem = n;
                    count = 1;
                }
            }else count++;
        }
        return elem;
    }
};
