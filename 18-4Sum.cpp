struct abcd{
    int a; int b; int c; int d;
    abcd(int _a, int _b, int _c, int _d):a(_a), b(_b), c(_c), d(_d){}
    bool operator==(const abcd& x) const {
        return a==x.a&&b==x.b&&c==x.c&&d==x.d;
    }
};
namespace std{
    template<>
    struct hash<abcd>{
        size_t operator()(const abcd& x) const {
            return (hash<int>()(x.a)^0x48373917)^
            (hash<int>()(x.a)^0x45937492)^
            (hash<int>()(x.a)^0x58305739)^
            (hash<int>()(x.a)^0x50287493);
        }
    };
}
class Solution {
public:
    unordered_set<abcd> r;
    unordered_map<int, int> n;
    vector<int> nums;
    vector<pair<int, int>> twoSum(int t){
        vector<pair<int, int>> res;
        for(int i = 0; i<nums.size(); i++){
            if(n.find(t-nums[i])!=n.end()&&n[t-nums[i]]!=i){
                res.push_back(make_pair(i, n[t-nums[i]]));
            }
        }
        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<=3) return res;
        this->nums = nums;
        for(int i = 0; i<nums.size(); i++){
            n[nums[i]]= i;
        }
        for(int i = 0; i<nums.size()-1; i++){
            for(int j = i+1; j<nums.size(); j++){
                auto abs = twoSum(target-nums[i]-nums[j]);
                for(const auto& ab: abs){
                    vector<int> s;
                    s.push_back(nums[ab.first]);
                    s.push_back(nums[ab.second]);
                    s.push_back(nums[i]);
                    s.push_back(nums[j]);
                    set<int> ss{ab.first, ab.second, i, j};
                    sort(begin(s), end(s));
                    auto aabbccdd = abcd(s[0], s[1], s[2], s[3]);
                    if(r.find(aabbccdd)==r.end()&&ss.size()==4){
                        r.insert(aabbccdd);
                    }
                }
            }
        }
        for(const auto& rr :r){
            vector<int> i;
            i.push_back(rr.a);
            i.push_back(rr.b);
            i.push_back(rr.c);
            i.push_back(rr.d);
            res.push_back(i);
        }
        return res;
    }
};
