class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        if(nums.size()==0) return 0;
        nums.push_back(-1);
        stack<pair<int, int>> stk;
        vector<int> numberOfHopsToNextLesserElem(nums.size()-1);
        for(int i = 0; i<nums.size(); i++){
            while(!stk.empty()&&stk.top().first>nums[i]){
                numberOfHopsToNextLesserElem[stk.top().second] =
                    i-stk.top().second;
                stk.pop();
            }
            stk.push({nums[i], i});
        }
        int res = 0;
        for(const auto& c : numberOfHopsToNextLesserElem){
            cout<<c<<" ";
            res+=c;
        }
        return res;
    }
};
