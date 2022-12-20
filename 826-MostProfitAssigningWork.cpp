class Solution {
public:
    struct job{
        int d;
        int p;
        int m;
        job(int _d, int _p, int _m):d(_d), p(_p), m(_m){}
        bool operator<(const job& j) const {
            return d<j.d;
        }
    };
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<job> jobs;
        for(int i = 0; i<d.size(); i++){
            jobs.push_back({d[i], p[i], p[i]});
        }
        sort(jobs.begin(), jobs.end());
        int r = jobs[0].p;
        for(int i = 0; i<jobs.size(); i++){
            r = max(r, jobs[i].p);
            jobs[i].m = r;
        }
        int res{};
        for(const auto& c : w){
            auto tj = job(c, -1, -1);
            auto j = upper_bound(jobs.begin(), jobs.end(), tj);
            if(j!=jobs.begin()){
                j = prev(j);
                cout<<"for "<<c<<" adding "<<(*j).d<<" with profit "<<(*j).p<<endl;
                res+=(*j).m;
            }
        }
        return res;
    }
};
