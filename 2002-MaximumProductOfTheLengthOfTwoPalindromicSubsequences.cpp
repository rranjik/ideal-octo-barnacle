class Solution {
public:
    vector<vector<int>> c;
    int dp(int i, int j){
        if(i>j) return 0;
        if(i==j) return 1;
        if(c[i][j]!=-1) return c[i][j];
        if(s[i]==s[j]) {
            auto res = dp(i+1, j-1)+2;
            c[i][j] = res; 
        }
        else {
            auto res = max(dp(i+1, j), dp(i, j-1));
            c[i][j] = res; 
        }
        return c[i][j];
    }
    string s;
    int LPS(string s) {
        c = vector<vector<int>>(s.length(), vector<int>(s.length(), -1));
        this->s = s;
        return dp(0, s.length()-1);
    }
    void split(string& s1, string& s2, int mask, int n, const string& s){
        for(int i = 0; i<n; i++){
            if(mask&(1<<i)){
                s1.push_back(s[i]);
            }else{
                s2.push_back(s[i]);
            }
        }
    }
    int maxProduct(string s) {
        this->s = s;
        int n = s.size();
        int res = 0;
        for(int i = 0; i<(1<<n); i++){
            string s1;
            string s2;
            split(s1, s2, i, n, s);
            //cout<<"i = "<<i<<" s1 = "<<s1<<" s2 = "<<s2<<endl;
            auto one = LPS(s1); 
            auto two = LPS(s2); 
            res = max(res, one*two);
        }
        return res;
    }
};
