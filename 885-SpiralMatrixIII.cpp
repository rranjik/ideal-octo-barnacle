class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int m, int n, int r, int c) {
        //order of turns matter (we follow what's required here)
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;
        int len = 0;
        vector<vector<int>> res = {{r, c}};
        while(res.size()<m*n){
            //the spiral increaes in radius every two turns
            if(d==0||d==2) len++;
            for(int i = 0; i<len; i++){
                r+=dir[d][0];
                c+=dir[d][1];
                if(r>=0&&r<m&&c>=0&&c<n){
                    res.push_back({r, c});
                }
            }
            d++;
            d%=4;
        }
        return res;
    }
};
