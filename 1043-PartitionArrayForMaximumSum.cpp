class Solution {
public:
    vector<int> a;
    int k;
    int maxi(const int i, int l){
        auto cp = l;
        if(i>=0){
            int res = -1;
            int n = 0;
            while(((i-n)>=0)&&l){
                res = max(res, a[i-n]);
                l--;
                n++;
            }
            if(l) return 0;
            //cout<<"maxi("<<i<<", "<<cp<<") = "<<res<<endl;
            return res;
        }
        //cout<<"maxi("<<i<<", "<<l<<") = 0"<<endl;
        return 0;//numeric_limits<int>::max();
    }
    vector<int> cache;
    int dp(int i){
        if(i>=0&&cache[i]!=-1) return cache[i];
        //cout<<"i = "<<i<<endl;
        if(i<0){
            //cout<<"dp("<<i<<") = "<<0<<endl;
            //cache[i] = 0;
            return 0;
        }
        else {
            int res = -1;
            for(int j = 1; j<=k; j++){
                int m = maxi(i, j);
                //cout<<"i = "<<i<<"; j = "<<j<<" max("<<res<<", "<<m*j<<")"<<endl;
                res = max(res, dp(i-j)+(m*j));
            }
            //cout<<"dp("<<i<<") = "<<res<<endl;
            cache[i] = res;
            return res;
        }
    }
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        a = A;
        k = K;
        cache = vector<int>(a.size(), -1);
        return dp(a.size()-1);
    }
};
