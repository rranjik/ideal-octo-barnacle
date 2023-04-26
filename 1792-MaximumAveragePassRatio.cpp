class Solution {
public:
    struct klass{
        double avg{};
        double p{};
        double t{};
        double ni{};
        klass(double _p, double _t):p(_p), t(_t){
            avg = (double(p))/(double(t));
            ni = ((p+1)/(t+1))-(avg);
        }
        bool operator<(const klass& c)const{
            return ni<c.ni;
        }
        bool operator>(const klass& c)const{
            return ni>c.ni;
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<klass, vector<klass>, less<klass>> q;
        int no{};
        for(const auto& c : classes){
            if(c[0]!=c[1]){
                q.push({(double)c[0], (double)c[1]});
            }else no++;
        }
        while(q.size()&&extraStudents){
            auto k = q.top(); q.pop();
            //cout<<"old klass = "<<k.p<<"/"<<k.t<<" "<<k.avg<<endl;
            auto nk = klass(k.p+1, k.t+1);
            //cout<<"new klass = "<<nk.p<<"/"<<nk.t<<" "<<nk.avg<<endl;
            q.push({(double)k.p+1, (double)k.t+1});
            extraStudents--;
        }
        //cout<<"********"<<endl;
        double sum{};
        int n{};
        while(q.size()){
            auto k = q.top(); q.pop();
            //cout<<"klass = "<<k.p<<"/"<<k.t<<" "<<k.avg<<endl;
            sum+=k.avg;
            n++;
        }
        sum+=no;
        n+=no;
        //cout<<"----------"<<endl;
        return sum/n;
    }
};
