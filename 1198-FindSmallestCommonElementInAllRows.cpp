class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        for(int i = 0; i<mat[0].size(); i++){
            int prop = mat[0][i];
            int found = 0;
            for(int j = 1; j<mat.size(); j++){
                auto lbit = 
                    lower_bound(begin(mat[j]), end(mat[j]), prop);
                if(lbit!=end(mat[j])){
                    if(*lbit == prop) found++;
                }
            }
            if(found == mat.size()-1) return prop;
        }
        return -1;
    }
};
