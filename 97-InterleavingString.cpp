class Solution {
public:
    vector<vector<int>> mem;
    int m;
    int n;
    string a;
    string b;
    string c;
    bool dp(int i, int j, int k){
        cout<<"i = "<<i<<"; j = "<<j<<"; k = "<<k<<endl;
        if(i==m) {
            auto suffb = b.substr(j, string::npos);
            auto suffc = c.substr(k, string::npos);
            return suffb==suffc;
        }
        if(j==n){
            auto suffa = a.substr(i, string::npos);
            auto suffc = c.substr(k, string::npos);
            return suffa==suffc;
        }
        if(mem[i][j]!=-1) return mem[i][j];
        bool res = false;
        if(((c[k]==a[i])&&dp(i+1, j, k+1))||((c[k]==b[j])&&dp(i, j+1, k+1))) res = true;
        mem[i][j] = res;
        return res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n = s2.length();
        a = s1; b = s2; c = s3;
        mem = vector<vector<int>>(m, vector<int>(n, -1));
        if(s1.length()+s2.length()!=s3.length()) return false;
        return dp(0, 0, 0);
    }
};
