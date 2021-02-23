class Solution {
public:
    double xl;
    double xr;
    double yl;
    double yu;
    double xc;
    double yc;
    double r;
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        xc = x_center;
        yc = y_center;
        xl = x_center - radius;
        xr = x_center + radius;
        yl = y_center - radius;
        yu = y_center + radius;
    }
    double dist(double x1, double y1){
        return sqrt(pow(abs(x1-xc), 2) + pow(abs(y1-yc), 2));
    }
    vector<double> randPoint() {
        bool point_in = false;
        vector<double> res;
        while(!point_in){
            std::random_device rd;
            std::mt19937 gen(rd()); 
            std::uniform_real_distribution<> disx(xl, xr);
            std::uniform_real_distribution<> disy(yl, yu);
            double x = disx(gen);
            double y = disy(gen);
            if(dist(x, y)<=r){
                point_in = true;
                res.push_back(x);
                res.push_back(y);
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
