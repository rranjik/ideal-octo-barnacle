namespace std{
    template<>
    struct hash<pair<int, int>>{
        size_t operator()(const pair<int, int>& p) const{
            return (hash<int>()(p.first)^0x29489287)^
            (hash<int>()(p.second)^0xF2048A293);
        }
    };
}
class Solution {
public:
    int total = 0;
    vector<int> n;
    unordered_map<pair<int, int>, bool> c;
    bool dfs(int i, int sum){
        auto coor = pair<int, int>(i, sum);
        if(c.find(coor)!=c.end()) return c[coor];
        if(sum>total/2) {
            c[coor] = false;
            return false;
        }
        if(sum*2==total) {
            c[coor] = true;
            return true;
        }
        if(i<0) {
            c[coor] = false;
            return false;
        }
        auto res = dfs(i-1, sum+n[i]) || dfs(i-1, sum);
        c[coor] = res;
        return res;
    }
    bool canPartition(vector<int>& nums) {
        n = nums;
        for(const auto& e : nums){
            total += e;
        }
        if(total%2) return false;
        return dfs(nums.size()-1, 0);
    }
};
