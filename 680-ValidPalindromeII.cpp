class Solution {
public:
    bool isPal(int i, int j, string s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        int vio = 0;
        while(i<j){
            if(s[i]!=s[j]){
                break;
            }
            else {
                i++;
                j--;
            }
        }
        if(i>=j) return true;
        return isPal(i+1, j, s) || isPal(i, j-1, s);
    }
};
