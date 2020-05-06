class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> cum;
        int rs = 0;
        for(int i = 0; i<arr.size(); i++){
            rs^=arr[i];
            cum.push_back(rs);
        }
        vector<int> res;
        for(const auto q:queries){
            if(q[0]==0) res.push_back(cum[q[1]]);
            else {
                int r = cum[q[1]]^cum[q[0]-1];
                res.push_back(r);
            }
        }
        return res;
    }
};
