class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> f;
        //max odd
        int res = 0;
        int mo = 0;
        char moc = ' ';
        for(const auto& c : s){
            f[c]++;
        }
        for(auto it : f){
            if(it.second%2){
                if(it.second>mo) {
                    mo = it.second;
                    moc = it.first;
                }
            }
        }
        res+=mo;
        for(auto it : f){
            if(!(it.second%2)){
                res+=it.second;
            }else{
                if(moc!=it.first)
                    res+=it.second-1;
            }
        }
        return res;
    }
};
