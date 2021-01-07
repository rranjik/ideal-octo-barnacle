class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxtypes, int trucksize) {
        sort(boxtypes.begin(), boxtypes.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1]>b[1];
        });
        int curr{};
        int res{};
        for(int i = 0; i<boxtypes.size(); i++){
            if(curr+boxtypes[i][0]<=trucksize){
                curr+=boxtypes[i][0];
                res+=boxtypes[i][1]*boxtypes[i][0];
            }else{
                res+=boxtypes[i][1]*(trucksize-curr);
                break;
            }
        }
        return res;
    }
};
