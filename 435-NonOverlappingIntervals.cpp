class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, 
                                                   const vector<int>& b){
                                                       return a[1]<b[1];
                                                   });
        int le = numeric_limits<int>::min();
        int inc{};
        for(int i = 0; i<intervals.size(); i++){
            if(intervals[i][0]>=le){
                inc++;
                le = intervals[i][1];
            }
        }
        return intervals.size()-inc;
    }
};
