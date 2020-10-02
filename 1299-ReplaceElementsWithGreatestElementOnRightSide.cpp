class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxi = arr[arr.size()-1];
        vector<int> res;
        res.push_back(-1);
        for(int i = arr.size()-2; i>=0; i--){
            res.push_back(maxi);
            maxi = max(maxi, arr[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
