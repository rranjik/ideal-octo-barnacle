class Solution {
public:
    const int mod = (int)(1e9+7);
    unordered_map<int, unordered_map<char, int>> c;
    int dp(int left, char last){
        if(c.find(left)!=c.end()&&c[left].find(last)!=c[left].end()){
            return c[left][last];
        }
        if(left==0) {
            c[left][last] = 1;
            return 1;
        }
        int res = 0;
        switch(last){
            case 'a':{
                res+=(dp(left-1, 'e')%mod);
                res%=mod;
            }break;
            case 'e':{
                res+=(dp(left-1, 'a')%mod);
                res%=mod;
                res+=(dp(left-1, 'i')%mod);
                res%=mod;
            }break;
            case 'i':{
                res+=(dp(left-1, 'a')%mod);
                res%=mod;
                res+=(dp(left-1, 'e')%mod);
                res%=mod;
                res+=(dp(left-1, 'o')%mod);
                res%=mod;
                res+=(dp(left-1, 'u')%mod);
                res%=mod;
            }break;
            case 'o':{
                res+=(dp(left-1, 'i')%mod);
                res%=mod;
                res+=(dp(left-1, 'u')%mod);
                res%=mod;
            }break;
            case 'u':{
                res+=(dp(left-1, 'a')%mod);
                res%=mod;
            }break;
            default:{
                res+=(dp(left-1, 'a')%mod);
                res%=mod;
                res+=(dp(left-1, 'e')%mod);
                res%=mod;
                res+=(dp(left-1, 'i')%mod);
                res%=mod;
                res+=(dp(left-1, 'o')%mod);
                res%=mod;
                res+=(dp(left-1, 'u')%mod);
                res%=mod;
            }
        }
        c[left][last] = res%mod;
        return res%mod;
    }
    int countVowelPermutation(int n) {
        return dp(n, ' ');
    }
};
