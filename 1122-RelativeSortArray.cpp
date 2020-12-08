class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        map<int, int> f;
        for(const auto& n : arr1){
            f[n]++;
        }
        for(const auto& n : arr2){
            res.push_back(n);
            f[n]--;
            while(f[n]){
                res.push_back(n);
                f[n]--;
            }
        }
        for(auto it : f){
            if(it.second){
                int k = it.first;
                int r = it.second;
                while(r){
                    res.push_back(k);
                    r--;
                }
            }
        }
        return res;
    }
};
