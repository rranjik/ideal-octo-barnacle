class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int search_range = arr.size();
        vector<int> res;
        for(int i = 0; i<arr.size(); i++){
            auto mi = max_element(arr.begin(), arr.begin()+search_range) - arr.begin();
            reverse(arr.begin(), arr.begin()+mi+1);
            res.push_back(mi+1);
            reverse(arr.begin(), arr.begin()+search_range);
            res.push_back(search_range);
            search_range--;
        }
        return res;
    }
};
