class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int> c(101); 
        vector<int> res;
        for(const auto& arr: arrays){
            for(const auto& e : arr){
                c[e]++;
                if(c[e]==arrays.size()) res.push_back(e);
            }
        }
        return res;
    }
};
