class Solution {
public:
    bool isPal(int i, int j, const auto& s){
        if(i>=j) return true;
        if(s[i]==s[j]) return isPal(i+1, j-1, s);
        return false;
    }
    int removePalindromeSub(string s) {
        if(s.length()==0)return 0;
        if(isPal(0, s.length()-1, s)) return 1;
        else return 2;
    }
};
