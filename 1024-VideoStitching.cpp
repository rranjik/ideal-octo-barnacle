class Interval{
public:
    int s;
    int e;
    Interval(int _s, int _e) : s(_s), e(_e) {}
    bool operator<(const Interval& i) const {
        if(s==i.s){
            return e<i.e;
        }
        return s<i.s;
    }
    bool operator==(const Interval& i) const {
        return i.s==s&&i.e==e;
    }
};
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<Interval> intervals;
        for(const auto& c : clips){
            intervals.push_back(Interval(c[0], c[1]));
        }
        sort(begin(intervals), end(intervals));
        intervals.erase(unique(begin(intervals), end(intervals)), end(intervals));
        
        auto endsLater = [](const Interval& a, const Interval& b){
            return a.e<b.e;
        };
        
        priority_queue<Interval, 
        vector<Interval>, decltype(endsLater)> q(endsLater);
        
        //priority_queue<Interval> q;
        
        for(int i = 0; i<intervals.size(); i++){
            if(intervals[i].s>=T) continue;
            if(q.empty()){
                if(intervals[i].s!=0) return -1;
                q.push(intervals[i]);
            }else{
                if(intervals[i].s>q.top().e) return -1;
                if(intervals[i].e>=q.top().e&&q.top().e<T){
                    auto poppedInterval = q.top();
                    q.pop();
                    if(!q.empty()){
                        if(q.top().e>=intervals[i].s){
                            q.push(intervals[i]);
                        }else{
                            q.push(poppedInterval);
                            q.push(intervals[i]);
                        }
                    }else{
                        if(intervals[i].s==0){
                            q.push(intervals[i]);
                        }else{
                            q.push(poppedInterval);
                            q.push(intervals[i]);
                        }
                    }
                }
            }
        }
        if(q.empty()&&T) return -1;
        if(q.top().e<T) return -1;
        return q.size();
    }
};
