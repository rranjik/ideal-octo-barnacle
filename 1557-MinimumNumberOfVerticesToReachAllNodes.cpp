class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> v(n);
        for(const auto& e : edges){
            v[e[1]] = true;
        }
        vector<int> res;
        for(int i = 0; i<n; i++){
            if(!v[i]) res.push_back(i);
        }
        return res;
    }
};
