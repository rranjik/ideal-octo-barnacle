class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size()==0){
            return res;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0]<b[0];});
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int> l = res[res.size()-1];
            if(intervals[i][0]<=l[1]){
                res.pop_back();
                vector<int> n = {l[0], (intervals[i][1]>l[1]?(intervals[i][1]):l[1])};
                res.push_back(n);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
