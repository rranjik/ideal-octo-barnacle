class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        while(s.length()-i>=2*k){
            reverse(s.begin()+i, s.begin()+i+k);
            i += 2*k;
        }
        if(s.length()-i<k){
            reverse(s.begin()+i, s.end());
        }else{
            reverse(s.begin()+i, s.begin()+i+k);
        }
        return s;
    }
};
