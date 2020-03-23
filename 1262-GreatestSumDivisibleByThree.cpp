class Solution {
public:
    //(2,4)->18
    //map<pair<int, int>, int> cm;
    //(2,1)->14
    map<pair<int, int>, int> cd;
    vector<int> n;
    int dp(int i, int rs){
        auto coor = make_pair(i, rs%3);
        if(cd.find(coor)!=cd.end()) return rs+cd[coor];
        if(i==-1) return ((rs%3)?-1:rs);
        auto r = max(dp(i-1, rs+n[i]),dp(i-1, rs));
        //cm[coor] = r;
        cd[coor] = r-rs;
        return r;
    }
    int maxSumDivThree(vector<int>& nums) {
        n = nums;
        return dp(nums.size()-1, 0);
    }
};
