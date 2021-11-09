class evnt{
public:
    int s;
    int e;
    evnt(int _s, int _e):s(_s), e(_e){}
    bool operator<(const evnt& i) const {
        if(s==i.s) return e<i.e;
        return s<i.s;
    }
};
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int mind = numeric_limits<int>::max();
        int maxd = numeric_limits<int>::min();
        vector<evnt> evnts;
        for(const auto& e : events){
            mind = min(mind, e[0]);
            maxd = max(maxd, e[1]);
            evnts.push_back(evnt(e[0], e[1]));
        }
        sort(begin(evnts), end(evnts));
        priority_queue<int, vector<int>, greater<int>> q;
        int n = evnts.size();
        int res = 0;
        //event number
        int en = 0;
        for(int i = mind; i<=maxd; i++){
            //push all events that start today
            while(en<n&&evnts[en].s==i){
                q.push(evnts[en].e);
                //never goind back to this event again
                en++;
            }
            //throw away all events that ended before today - can't attend anyway
            while(q.size()&&q.top()<i){
                q.pop();
            }
            //if there is still an event that ends today or later, attend the event that 
            //earliest(q min heap by end times) among all of them
            if(q.size()){
                q.pop();
                res++;
            }
        }
        return res;
    }
};
