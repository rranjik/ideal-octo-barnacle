class Solution {
public:

    int bestClosingTime(string customers) {
        //from hints:
        //At any index, the penalty is the sum of 
        //prefix count of ‘N’ and suffix count of ‘Y’.
        int n = customers.size();
        //one extra because we might have to close the 
        //shop at the hour on the last hour
        //ex: YYYY close on hour 4 nor 3 (string index only goes
        //up to 3 though)
        vector<int> pn(n+1), sy(n+1);
        for(int i = 1; i<=n; i++){
            pn[i] = pn[i-1]+(customers[i-1]=='N'?1:0);
        }
        for(int i = n-1; i>=0; i--){
            sy[i] = sy[i+1]+(customers[i]=='Y'?1:0);
        }
        for(const auto& x : pn) cout<<x<<" "; cout<<endl;
        for(const auto& y : sy) cout<<y<<" "; cout<<endl;
        int res = 1e9;
        int resh = -1;
        for(int i = 0; i<=n; i++){
            if( res > pn[i]+ sy[i]){
                resh = i;
                res = pn[i]+sy[i];
            }
        }
        return resh;
    }
};
