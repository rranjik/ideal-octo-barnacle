class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long res = 0;
        unordered_map<int, int> m;
        for(const auto& r : roads){
            m[r[0]]++;
            m[r[1]]++;
        }
        vector<long long> v;
        for(const auto& [x, d]:m){
            v.push_back(d);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for(int i = 0; i<v.size(); i++){
            res+=(v[i]*n);
            n--;
        }
        return res;
    }
};
