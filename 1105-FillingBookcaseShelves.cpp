class Solution {
public:
    vector<vector<int>> b;
    int s;
    int n;
    int height(int c, int l){
        //if(l==-1){
        //    cout<<"height("<<c<<", "<<l<<") = "<<b[c][1]<<endl;
        //    return b[c][1];
        //} else{
            int res = 0;
            for(int i = c; i>l; i--){
                res = max(res, b[i][1]);
            }
            //cout<<"height("<<c<<", "<<l<<") = "<<res<<endl;
            return res;
        //}
    }
    int width(int c, int l){
        //if(l==-1){
        //    cout<<"width("<<c<<", "<<l<<") = "<<b[c][0]<<endl;
        //    return b[c][0];
        //} else{
            int res = 0;
            for(int i = c; i>l; i--){
                res +=b[i][0];
            }
            //cout<<"width("<<c<<", "<<l<<") = "<<res<<endl;
            return res;
        //}
    }
    unordered_map<int, int> c;
    int dp(int l){
        if(c.find(l)!=c.end())return c[l];
        //cout<<"dp("<<l<<")"<<endl;
        if(l==n-1){
            c[l] = 0;
            return 0;
        }
        int res = numeric_limits<int>::max();
        for(int j = l+1; j<n&&width(j, l)<=s; j++){
            auto dpj = dp(j);
            //cout<<"dp("<<j<<") = "<<dpj<<endl;
            res = min(res, dpj+height(j, l));
        }
        //cout<<"dp("<<l<<")="<<res<<endl;
        c[l] = res;
        return res;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        s = shelf_width;
        b = books;
        n = b.size();
        return dp(-1);
    }
};
