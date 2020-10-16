class Solution {
public:
    bool isPal(int i, int j, const string& s){
        auto sc = s;
        reverse(begin(sc), end(sc));
        return s==sc;
    }
    bool tryPal(const string& s){
        for(int i = 0, j=s.length()-1; i<s.length()&&j>=0; i++, j--){
            if(s[i]!=s[j]){
                auto woi = s;
                woi.erase(woi.begin()+i);
                auto woj = s;
                woj.erase(woj.begin()+j);
                auto woip = isPal(0, woi.length()-1, woi);
                auto wojp = isPal(0, woj.length()-1, woj);
                return woip||wojp;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        return tryPal(s);
    }
};
