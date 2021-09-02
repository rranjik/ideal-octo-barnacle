class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int, vector<int>, greater<int>> q1;
        priority_queue<int, vector<int>, less<int>> q2;
        for(const auto& n : nums1){
            q1.push(n);
        }
        for(const auto& n : nums2){
            q2.push(n);
        }
        int res = 0;
        while(!q1.empty()){
            auto a = q1.top(); q1.pop();
            auto b = q2.top(); q2.pop();
            res+=(a*b);
        }
        return res;
    }
};
