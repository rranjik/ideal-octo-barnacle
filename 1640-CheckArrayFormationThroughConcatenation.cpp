class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> l;
        for(int i = 0; i<arr.size(); i++){
            l[arr[i]] = i;
        }
        unordered_set<int> p;
        for(const auto& ap : pieces){
            for(const auto& an : ap){
                p.insert(an);
            }
        }
        for(const auto& n : arr){
            if(p.find(n)==p.end()) return false;
        }
        for(const auto& ap : pieces){
            auto s = ap[0];
            auto si = l[s];
            for(int i = si, j = 0; j<ap.size(); i++, j++){
                if(i>=arr.size()) return false;
                if(arr[i]!=ap[j]) return false;
            }
        }
        return true;
    }
};
