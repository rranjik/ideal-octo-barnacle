/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        auto cmp = [](const Interval& a, const Interval& b)
        {return a.start>b.start;};
        priority_queue<Interval, vector<Interval>, decltype(cmp)> q(cmp);
        for(const auto e : schedule){
            for(const auto i : e){
                q.push(i);
            }
        }
        int me = numeric_limits<int>::min();
        vector<Interval> res;
        while(!q.empty()){
            Interval i = q.top();
            q.pop();
            if(i.start>me&&me!=numeric_limits<int>::min()){
                res.push_back(Interval(me, i.start));
            }
            me = max(me, i.end);
        }
        return res;
    }
};
