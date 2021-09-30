class point{
public:
    double x; double y;
    point(double _x, double _y):x(_x), y(_y){}
    bool operator==(const point& p)const {
        return x==p.x&&y==p.y;
    }
};
namespace std{
    template <> 
    struct hash<point>{
        size_t operator()(const point& p) const{
            return (hash<double>()(p.x)^0x2948393)^
            (hash<double>()(p.y)^0xF204E243);
        }
    };
}
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        double minx = numeric_limits<int>::max();
        double maxx = numeric_limits<int>::min();
        unordered_set<point> ps;
        for(const auto& p : points){
            auto pp = point(p[0], p[1]);
            ps.insert(pp);
            minx = min(minx, (double) p[0]);
            maxx = max(maxx, (double) p[0]);
        }
        double proposedy = (minx+maxx)/(2.0);
        cout<<"proposedy "<<proposedy<<endl;
        for(const auto& p: points){
            double refx;
            if(p[0]>=proposedy){
                refx = (proposedy-(p[0]-proposedy));
            }else{
                refx = (proposedy+(proposedy-p[0]));
            }
            cout<<"for p("<<p[0]<<", "<<p[1]<<")";
            cout<<" expecting r("<<refx<<", "<<p[1]<<")"<<endl;
            //int distx = abs(p[0]-proposedy);
            if(ps.find(point(refx, p[1]))==ps.end()){
            //(ps.find(point(p[0]-distx, p[1]))==ps.end())){
                return false;
            }
            //else {
            //    ps.erase(ps.find(point(p[0], refy)));
            //    ps.erase(ps.find(point(p[0], p[1])));
            //}
        }
        return true;
    }
};
