class Solution {
public:
    using pii = pair<int, int>;
    //map<pii, int> slopes;
    unordered_map<double, int> slopes;
    vector<vector<int>> p;
    //horizontal lines
    int h;
    pii addSlope(int i, int j, int c, int d){
        int x1 = p[i][0];
        int y1 = p[i][1];
        int x2 = p[j][0];
        int y2 = p[j][1];
        if((x1==x2)&&(y1==y2)) d++;
        else if(y1==y2){
            h++;
            c = max(h, c);
        }else{
            auto slopeij = 1.0*(x1-x2)/(y1-y2);
            if(slopes.find(slopeij)==slopes.end()) slopes[slopeij] = 1;
            slopes[slopeij]++;
            c = max(slopes[slopeij], c);
        }
        return {c, d};
    }
    int maxPointsOnAnyLineThroughi(int i){
        slopes.clear();
        h = 1;
        //count
        int c = 1;
        //duplicates 
        int d = 0;
        for(int j = 0; j<p.size(); j++){
            if(j!=i){
                auto r = addSlope(i, j, c, d);
                c = r.first;
                d = r.second;
            }
        }
        return c+d;
    }
    int maxPoints(vector<vector<int>>& points) {
        p = points;
        if(points.size()<3) return points.size();
        
        int maxPoints = 1;
        for(int i = 0; i<points.size()-1; i++){
            maxPoints = max(maxPoints, maxPointsOnAnyLineThroughi(i));
        }
        return maxPoints;
    }
};
