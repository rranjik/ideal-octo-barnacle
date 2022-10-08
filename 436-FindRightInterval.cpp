class Solution {
public:
    //interval with index
    struct intvi{
        int s;
        int e;
        int i;
        intvi(int _s, int _e, int _i):s(_s), e(_e), i(_i){}
        bool operator<(const intvi& o)const {
            return this->s<o.s;
        }
    };
    vector<int> findRightInterval(vector<vector<int>>& e) {
        //e = events
        //ei = events with index
        vector<intvi> ei;
        for(int i = 0; i<e.size(); i++){
            ei.push_back({e[i][0], e[i][1], i});
        }
        sort(ei.begin(), ei.end());
        vector<int> res(e.size(), -1);
        for(int i = 0; i<e.size()-1; i++){
            auto j = i+1;
            while(j<e.size()&&ei[j].s<ei[i].e){
                j++;
            }
            res[ei[i].i] = j<e.size()?ei[j].i:-1;
        }
        return res;
    }
};
