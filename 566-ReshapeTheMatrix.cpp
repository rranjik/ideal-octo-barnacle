class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<int> n;
        if(!nums.size()) return {};
        int ro = nums.size();
        int co = nums[0].size();
        int s = ro* co;
        if(r*c!=s) return nums;
        for(const auto& row : nums){
            for(const auto& t : row){
                n.push_back(t);
            }
        }
        auto res = vector<vector<int>>(r, vector<int>(c));
        int k = 0;
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                res[i][j] = n[k];
                k++;
            }
        }
        return res;
    }
};
