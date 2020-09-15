class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> a;
        for(const auto& n : nums1){
            a.insert(n);
        }
        multiset<int> b;
        for(const auto& n : nums2){
            b.insert(n);
        }
        std::vector<int> v_intersection;
 
    std::set_intersection(a.begin(), a.end(),
                          b.begin(), b.end(),
                          std::back_inserter(v_intersection));
        return v_intersection;
    }
};
