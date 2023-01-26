class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int K) {
        vector<int> q;
        int n = nums.size();
        for(int i = 0; i<nums.size(); i++){
            auto rem = n-i-1;
            while(q.size()&&nums[i]<q.back()&&(rem+q.size())>=K){
                q.pop_back();
            }
            q.push_back(nums[i]);
        }
        return {q.begin(), q.begin()+K};
    }
};
