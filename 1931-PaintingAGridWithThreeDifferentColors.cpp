class Solution {
public:
    vector<vector<int>> dp = vector<vector<int>>(1001, vector<int>(1024));
    int colorTheGrid(int m, int n, int i = 0, int j = 0, int cur = 0, int prev = 0) {
        bitset<32> bsc(cur);
        bitset<32> bsp(prev);
        //cout<<"cur = "<<bsc.to_string()<<" prev = "<<bsp.to_string()<<endl;
        if(i==m) return colorTheGrid(m, n, 0, j+1, 0, cur);
        if(j==n) return 1;
        if((i==0)&&(dp[j][prev])) return dp[j][prev];
        int res = 0;
        int up = 0; 
        int left = 0;
        int mod = 1e9+7;
        if(i==0) up = 0;
        else {
            auto posOfPrevColorInSameCol = 3<<((i-1)*2);
            //cout<<"posOfPrevColorInSameCol = "<<posOfPrevColorInSameCol<<endl;
            up = cur&posOfPrevColorInSameCol;
            up>>=((i-1)*2);
        }
        auto posOfColorToLeft = 3<<(i*2);
        //cout<<"posOfColorToLeft = "<<posOfColorToLeft<<endl;
        left = prev&posOfColorToLeft;
        left>>=(i*2);
        //cout<<"up = "<<up<<" left = "<<left<<endl;
        for(int k = 1; k<=3; k++){
            if(k!=left&&k!=up){
                auto posOfCurrColor = k<<(i*2);
                auto ncurr = cur|posOfCurrColor;
                res = (res + colorTheGrid(m, n, i+1, j, ncurr, prev))%mod;
            }
        }
        if(i==0) dp[j][prev] = res;
        return res;
    }
};
