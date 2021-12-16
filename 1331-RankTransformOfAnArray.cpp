class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set s(arr.begin(), arr.end());
        //num to rank
        unordered_map<int, int> ntr;
        int i = 1;
        for(const auto& it : s){
            ntr[it] = i;
            i++;
        }
        for(auto& a : arr){
            a = ntr[a];
        }
        return arr;
    }
};
