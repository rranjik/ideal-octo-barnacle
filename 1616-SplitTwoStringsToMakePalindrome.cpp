class Solution {
public:
    bool isPali(string& s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool check(string a, string b){
        int i = 0;
        auto n = a.size();
        for(; i<n; i++){
            int j = n-i-1;
            if(a[i]!=b[j]) break;
        }
        return isPali(a, i, n-i-1)||isPali(b, i, n-i-1);
    }
    bool checkPalindromeFormation(string a, string b) {
        return check(a,b)||check(b,a);
    }
};
