class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> a;
        set<int> b;
        for(const auto& n : nums1){
            a.insert(n);
        }
        for(const auto& n : nums2){
            b.insert(n);
        }
        vector<int> res;
        set_intersection(begin(a), end(a), begin(b), end(b), back_inserter(res));
        return res;
    }
};
