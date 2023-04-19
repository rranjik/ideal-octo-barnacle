class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = -1;
        int mres = 1e9;
        for(int i = 0; i<points.size(); i++){
            if(points[i][0] == x||points[i][1] == y){
                if(mres>(abs(points[i][0] - x)+abs(points[i][1] - y))){
                    mres = abs(points[i][0] - x)+abs(points[i][1] - y);
                    res = i;
                }
            }
        }
        return res;
    }
};
