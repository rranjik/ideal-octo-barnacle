class balloon{
public:
    int s;
    int e;
    balloon(int _s, int _e):s(_s), e(_e){}
    bool operator<(const balloon& b) const {
        if(s==b.s){
            return e<b.e;
        }
        return s<b.s;
    }
};
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(!points.size()) return 0;
        vector<balloon> balloons;
        for(const auto& p : points){
            balloons.push_back({p[0], p[1]});
        }
        int len = points.size();
        sort(begin(balloons), end(balloons));
        int res = 0;
        res++;
        balloon in = balloons[0];
        int le = 0;
        for(int i = 1; i<balloons.size(); i++){
            if(balloons[i].s<=in.e){
                in.s = balloons[i].s;
                in.e = min(balloons[i].e, in.e);
            }else{
                res++;
                in.s = balloons[i].s;
                in.e = balloons[i].e;
                le = i;
            }
        }
        return res;
    }
};
