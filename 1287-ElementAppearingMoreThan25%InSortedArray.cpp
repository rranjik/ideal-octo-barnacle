class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        for(const auto i : {n/4, n/2, n*3/4}){
            auto e = arr[i];
            auto its = lower_bound(arr.begin(), arr.begin()+i, arr[i]);
            auto ite = upper_bound(arr.begin()+i, arr.end(), arr[i]);
            if(ite-its>n/4) return arr[i];
        }
        return 0;
    }
};
