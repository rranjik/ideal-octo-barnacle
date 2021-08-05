class Solution {
public:
    void dfs(int i, vector<int> curr, vector<vector<int>>& res){
        //cout<<"dfs@ "<<i<<endl;
        if(i>=f.size()){
            res.push_back(curr);
            return;
        }
        dfs(i+1, curr, res);
        for(int j = 1; j<=f[i].second; j++){
            curr.push_back(f[i].first);
            dfs(i+1, curr, res);
        }
    }
    vector<pair<int, int>> f;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums[0];
        int li = 0;
        for(int i = 1; i<nums.size(); i++){
            if(l!=nums[i]){
                f.push_back({l, i-li});
                l = nums[i];
                li = i;
            }
        }
        f.push_back({l, nums.size()-li});
        for(const auto& n : f) cout<<n.first<<" occurs "<<n.second<<" times "<<endl;
        vector<vector<int>> res;
        vector<int> curr;
        dfs(0, curr, res);
        return res;
    }
};
