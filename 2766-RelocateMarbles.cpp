class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> s(nums.begin(), nums.end());
        for(int i = 0; i<moveFrom.size(); i++){
            s.erase(moveFrom[i]);
            s.insert(moveTo[i]);
        }
        vector<int> res;
        for(const auto& x : s){
            res.push_back(x);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
