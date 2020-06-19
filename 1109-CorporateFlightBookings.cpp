class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        vector<int> range(n, 0);
        for(const auto& b : bookings){
            range[b[0]-1] += b[2];
            if(b[1]<range.size()) range[b[1]] -= b[2];
        }
        int accum=0;
        for(int i = 0; i<n; i++){
            accum+=range[i];
            res[i]= accum;
        }
        return res;
    }
};
