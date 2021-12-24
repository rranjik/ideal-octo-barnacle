class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> fm;
        for(const auto& c : s) fm[c]++;
        map<int, vector<char>, greater<int>> ifm;
        for(const auto& it : fm) ifm[it.second].push_back(it.first);
        string res;
        for(const auto& it : ifm){
            for(const auto& c : it.second){
                res+=string(it.first, c);
            }
        }
        return res;
    }
};
