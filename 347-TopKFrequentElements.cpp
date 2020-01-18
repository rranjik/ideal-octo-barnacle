class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        for(const auto& n :nums){
            ++f[n];
        }
        priority_queue<pair<int, int>> tk;
        for(const auto it : f){
            tk.push({it.second, it.first});
        }
        vector<int> res;
        for(int i = 0; i <k; i++){
            res.push_back(tk.top().second); 
            tk.pop();
        }
        return res;
    }
};
