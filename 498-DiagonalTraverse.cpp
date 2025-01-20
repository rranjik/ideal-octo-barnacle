class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
        vector<vector<int>> dir = {{-1, 1}, {1, -1}};
        int d = 0;
        int r = 0; int c = 0;
        vector<int> res = {};
        int m = a.size(); int n = a[0].size();
        while(res.size()<m*n){
            cout<<"d = "<<d<<endl;
            while(r>=0&&r<m&&c>=0&&c<n){
                cout<<" a["<<r<<"]["<<c<<"] = "<<a[r][c]<<endl;
                res.push_back(a[r][c]);
                r+=dir[d][0];
                c+=dir[d][1];
            }
            if(d==0) {
                r++;
                if(c>=n){
                    c--; r++;
                }
            }else {
                c++;
                if(r>=m){
                    r--; c++;
                }
            }
            d = d+1;
            d%=2;
        }
        return res;
    }
};
