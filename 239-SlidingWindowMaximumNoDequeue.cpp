struct elem{
    int e;
    int i;
    elem(int _i, int _e):e(_e), i(_i){}
    bool operator==(const elem& p) const {
        return e==p.e&&i==p.i;
    }
};
namespace std{
    template<>
    struct hash<elem>{
        size_t operator()(const elem& p) const {
            return (hash<int>()(p.e)^0x94792823)^
            (hash<int>()(p.i)^0x19482949);
        }
    };
}
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<elem, int> s;
        multiset<int, greater<int>> m;
        vector<int> res;
        if(!nums.size()||!k) return res;
        for(int i = 0; i<k; i++){
            s.insert({elem(i, nums[i]), nums[i]});
            m.insert(nums[i]);
        }
        auto j = k;
        while(j<nums.size()){
            res.push_back(*m.begin());
            m.erase(m.find(s[elem(j-k, nums[j-k])]));
            s.insert({elem(j, nums[j]), nums[j]});
            m.insert(nums[j]);
            j++;
        }
        res.push_back(*m.begin());
        return res;
    }
};
