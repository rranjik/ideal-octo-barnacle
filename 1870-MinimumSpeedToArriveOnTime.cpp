class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int r = 1e7+1;
        int l = 1;
        auto last = dist[dist.size()-1];
        int res = -1;
        while(l<=r){
            cout<<"l = "<<l<<" r = "<<r<<endl;
            double m = (r+l)/2;
            //s = d/t
            //t = d/s
            double t = 0;
            for(const auto& d: dist){
                t += ceil(d/m);
            }
            t-=ceil(last/m);
            t+=(last/m);
            cout<<"at m = "<<m<<" it took "<<t<<" hrs to arrive"<<endl;
            if(t<hour){
                res = m;
                r = m-1;
            }else if(t>hour){
                l = m+1;
            }else return m;
        }
        return res;
    }
};
