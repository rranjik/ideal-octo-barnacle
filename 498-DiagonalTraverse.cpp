class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(!m) return res;
        int n = matrix[0].size();
        bool rev = true;
        for(int i = 0; i<n; i++){
            int si = 0; int ei = i;
            vector<int> inter;
            while(si<m&&ei>=0){
                inter.push_back(matrix[si][ei]);
                si++; ei--;
            }
            if(rev){
                reverse(inter.begin(), inter.end());
            }
            rev = !rev;
            res.insert(res.end(), inter.begin(), inter.end());
        }
        for(int i = 1; i<m; i++){
            int si = i;int ei = n-1;
            vector<int> inter;
            while(si<m&&ei>=0){
                inter.push_back(matrix[si][ei]);
                si++; ei--;
            }
            if(rev){
                reverse(inter.begin(), inter.end());
            }
            rev = !rev;
            res.insert(res.end(), inter.begin(), inter.end());
        }
        return res;
    }
};
