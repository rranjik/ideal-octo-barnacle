class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        map<int, vector<int>> m;
        for(int i = 0; i<B.size(); i++){
            m[B[i]].push_back(i);
        }
        vector<int> res;
        for(int j = 0; j<A.size(); j++){
            auto r = m[A[j]].back();
            m[A[j]].pop_back();
            res.push_back(r);
        }
        return res;
    }
};
