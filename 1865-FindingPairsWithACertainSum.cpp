class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        sort(n1.begin(), n1.end());
        n2 = nums2;
        for(const auto& n : nums2){
            m[n]++;
        }
        for(int i = 0; i<nums2.size(); i++){
            im[i] = nums2[i];
        }
    }
    vector<int> n1;
    vector<int> n2;
    unordered_map<int, int> m;
    unordered_map<int, int> im;
    void add(int index, int val) {
        auto oldv = im[index];
        auto newv = oldv+val;
        im[index] = newv;
        m[oldv]--;
        if(!m[oldv]){
            m.erase(oldv);
        }
        m[newv]++;
    }
    
    int count(int tot) {
        auto res = 0;
        for(const auto& n : n1){
            if(n<=tot){
                auto req = tot-n;
                if(m.find(req)!=m.end()){
                    res+=m[req];
                }
            }else{
                break;
            }
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
