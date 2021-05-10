class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        vector<pair<int, int>> mincors;
        vector<int> mins;
        for(int i = 0; i<matrix.size(); i++){
            int minsofar = numeric_limits<int>::max();
            pair<int, int> mincor = make_pair(-1, -1);
            for(int j = 0; j<matrix[i].size(); j++){
                if(minsofar>matrix[i][j]){
                    mincor = make_pair(i, j);
                    minsofar = matrix[i][j];
                }
            }
            mincors.push_back(mincor);
            mins.push_back(minsofar);
        }
        
        for(int j = 0; j<matrix[0].size(); j++){
            int maxincol = numeric_limits<int>::min();
            pair<int, int> maxcor = make_pair(-1, -1);
            for(int i = 0; i<matrix.size(); i++){
                if(maxincol<matrix[i][j]){
                    maxcor = make_pair(i, j);
                    maxincol = matrix[i][j];
                }
            }
            if(find(begin(mins), end(mins), maxincol)!=end(mins)) res.push_back(maxincol);
        }
        return res;
    }
};
