class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> ii(nums2.size(), -1);
        for(int i = 0; i<nums2.size(); i++){
            while(!s.empty()&&nums2[s.top()]<nums2[i]){
               ii[s.top()] = nums2[i]; 
               s.pop();
            }
            s.push(i);
        }
        unordered_map<int, int> m;
        for(int i = 0;i <ii.size(); i++){
            m.insert({nums2[i], ii[i]});
        }
        vector<int> res(nums1.size());
        for(int i = 0; i<nums1.size(); i++){
            res[i] = m[nums1[i]];
        }     
        return res;
    }
};
