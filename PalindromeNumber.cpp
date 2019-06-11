class Solution {
    bool isPalindrome(string s){
        if(s.length() == 0 || s.length() == 1)
            return true;
        else {
            if(s[0]==s[s.length()-1])
                return isPalindrome(string(s.begin()+1, s.end()-1));
            else
                return false;
        }
    }
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        return isPalindrome(s);
    }
};
