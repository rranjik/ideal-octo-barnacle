class Solution {
public:
    int countSubstrings(string s) {
        auto n = s.length();
        auto res = 0;
        for(int center = 0; center<(2*n)-1; center++){
            int l = center/2;
            int r = l + (center%2);
            while(l>=0&&r<n&&s[l]==s[r]){
                l--;r++;res++;
            }
        }
        return res;
    }
};
