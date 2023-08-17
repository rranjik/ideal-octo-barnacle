class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        //too lazy to write a hash function for 
        //pair<int, int>; a map is not needed here
        map<pair<int, int>, int> m;
        vector<pair<int, int>> o1, o2;
        for(int i = 0; i<img1.size(); i++){
            for(int j = 0; j<img1[i].size(); j++){
                if(img1[i][j]) o1.push_back({i,j});
                if(img2[i][j]) o2.push_back({i,j});
            }
        }
        int res = 0;
        for(const auto& oo1 : o1){
            for(const auto& oo2: o2){
                m[{oo1.first-oo2.first, oo1.second-oo2.second}]++;
                res = max(res, m[{oo1.first-oo2.first, oo1.second-oo2.second}]);
            }
        }
        return res;
    }
};
