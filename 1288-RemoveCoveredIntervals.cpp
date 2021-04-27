class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int res = 0;
        int r = -1;
        for(int i = 0; i<intervals.size(); i++){
            if(intervals[i][1]>r){
                r = intervals[i][1];
                res++;
            }
        }
        return res;
    }
};
