class Solution {
public:
    void print(const vector<int>& v) {
        for(const auto& n : v) {
            cout<<n<< " " ;
        }
        cout<<endl;
    }
    int distinctSubseqII(string s) {
        vector<int> dp = vector<int>(26);
        int mod = 1e9+7;
        int res = 0;
        for(int i = 0; i<s.size(); i++){
            //end positions
            cout<<"i = "<<i<<endl;
            int epos = s[i]-'a';
            int ehere = 0;
            for(int j = 0; j<26; j++){
                ehere+=dp[j];
                ehere%=mod;
            }
            dp[epos]=ehere;
            dp[epos]++;
            dp[epos]%=mod;
            //print(dp);
            //cout<<res<<endl;
        }
        for(int i = 0; i<26; i++) {
            res+=dp[i];
            res%=mod;
        }
        return res;
    }
};
