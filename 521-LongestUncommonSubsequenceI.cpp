class Solution {
public:
    int lcs(int i, int j){
        if(i<0||j<0)return 0;
        if(a[i]==b[j]){
            return lcs(i-1, j-1)+1;
        }else {
            return max(lcs(i-1, j), lcs(i, j-1));
        }
    }
    int n; int m; string a; string b;
    int findLUSlength(string a, string b) {
        n = a.length();
        m = b.length();
        if(a!=b) return max(n, m);
        else return -1;
        this->a = a; this->b = b;
        auto l = lcs(n-1, m-1);
        auto res = max(n-l, m-l);
        return res==0?-1:res;
    }
};
