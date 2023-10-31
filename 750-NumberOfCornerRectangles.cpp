class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
                map<pair<int, int>, int> m;
        int res = 0;
        for(int i = 0; i<grid.size(); i++){
            vector<int> ones;
            for(int j = 0; j<grid[i].size(); j++){
                if(grid[i][j]==1) {
                    for(const auto& p : ones){
                        auto pp = pair<int, int>(p, j);
                        res+= m[pp];
                        m[pp]++;
                    }
                    ones.push_back(j);
                }
            }
        }
        return res;
    }
};
