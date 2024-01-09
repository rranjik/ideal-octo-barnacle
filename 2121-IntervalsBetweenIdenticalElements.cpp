class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        vector<long long> res(arr.size(), 0);
        unordered_map<int, vector<int>> in;
        for(int i = 0; i<arr.size(); i++){
            in[arr[i]].push_back(i);
        }
        for(const auto& it : in){
            auto locs = it.second;
            for(int i = 1; i<locs.size(); i++){
                res[locs[0]] += (locs[i]-locs[0]);
            }
            
            for(int i = 1; i<locs.size(); i++){
                res[locs[i]] = res[locs[i-1]] 
                    - (locs[i]-locs[i-1])*(locs.size()-i-1)
                    + (locs[i]-locs[i-1])*(i-1);
            }
        }
        return res;
    }
};
