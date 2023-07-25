class Solution {
public:
    int n;
    unordered_map<int, unordered_map<int, int>> c;
    int toPal(const string& s, int i, int j){
        int res = 0;
        while(i<j){
            if(s[i]!=s[j]) res++;
            i++; j--;
        }
        return res;
    }
    int dfs(const string& s, int i, int k){
        cout<<"i = "<<i<<" k = "<<k<<endl;
        if(c.find(i)!=c.end()&&c[i].find(k)!=c[i].end()) return c[i][k];
        if(n-i==k) return 0;
        if(k==1) return toPal(s, i, n-1);
        int res = numeric_limits<int>::max();
        for(int j = i+1; j<=n-k+1; j++){
            res = min(res, dfs(s, j, k-1)+toPal(s, i, j-1));
        }
        cout<<"returning "<<(c[i][k] = res)<<endl;
        return c[i][k];
    }
    int palindromePartition(string s, int k) {
        n = s.size();
        return dfs(s, 0, k);
    }
};
