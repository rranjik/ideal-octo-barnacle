class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int s2 = numeric_limits<int>::min();
        for(int i = nums.size()-1; i>=0; i--){
            if(nums[i]<s2) return true;
            while(!s.empty()&&s.top()<nums[i]){
                s2 = s.top(); s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};
