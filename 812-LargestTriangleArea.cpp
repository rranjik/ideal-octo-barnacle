class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res{};
        for(int i = 0; i<points.size()-2; i++){
            for(int j = i+1; j<points.size()-1; j++){
                for(int k = j+1; k<points.size(); k++){
                    //x 1 y 2 + x 2 y 3 + x 3 y 1 − y 1 x 2 − y 2 x 3 − y 3 x 1
                    double area = 
                        (double)points[i][0]*points[j][1]+
                        (double)points[j][0]*points[k][1]+
                        (double)points[k][0]*points[i][1]-
                        (double)points[i][1]*points[j][0]-
                        (double)points[j][1]*points[k][0]-
                        (double)points[k][1]*points[i][0];
                    area = fabs(area);
                    area/=2;
                    cout<<"i = "<<i<<" j = "<<j<<" k = "<<k<<" area = "<<area<<endl;
                    res = max(res, area);
                }
            }
        }
        return res;
    }
};
