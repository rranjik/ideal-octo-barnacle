class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& l) {
        vector<double> p;
        int xx = l[0];
        int yy = l[1];
        int at = 0;
        for(const auto& m : points){
            auto x = m[0]; auto y = m[1];
            if(xx==x&&yy==y){
                at++;
                continue;
            }
            p.push_back(atan2(y-yy, x-xx)*(180/M_PI));
        }
        sort(p.begin(), p.end());
        vector<double> r;
        for(const auto& a : p){
            r.push_back(a+360);
        }
        p.insert(p.end(), r.begin(), r.end());
        int res = 0;
        int i = 0;
        int j = 0;
        while(j<p.size()){
            while(p[j]-p[i]>angle){
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res + at;
    }
};
