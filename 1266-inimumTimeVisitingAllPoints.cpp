class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i<points.size()-1; i++){
            auto a = points[i];
            auto b = points[i+1];
            int x = abs(a[0]-b[0]);
            int y = abs(a[1]-b[1]);
            int d = min(x, y);
            int s = max(x, y)-d;
            res += (d+s);
        }
        return res;
    }
};
