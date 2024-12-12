class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(),ranges.end());
        int start=ranges[0][0];
        int end=ranges[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<ranges.size();i++){
            if(end>=ranges[i][0])
            {
                start= min(start,ranges[i][0]);
                end = max(end, ranges[i][1]);
            }
            else
            {
                ans.push_back({start,end});
                start = ranges[i][0];
                end = ranges[i][1];
            }
        }
        ans.push_back({start,end});
        int set = ans.size();
        int res=1;
        int m = 1e9+7;
        while(set)
        {
            res = res*2;
            res= res%m;
            set--;
        }
        return res;
        
    }
};
