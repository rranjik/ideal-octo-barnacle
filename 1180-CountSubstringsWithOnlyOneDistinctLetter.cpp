class Solution {
public:
    int countLetters(string s) {
        int l = 0;
        int r = 0;
        int res = 0;
        while(r<s.length()){
            cout<<"r = "<<r<<"; l = "<<l<<endl;
            while(r<s.length()&&s[r]==s[l]){
                r++;
            }
            int n = (r-1)-l+1;
            cout<<"n = "<<n<<endl;
            cout<<"adding "<<((n*(n+1))/2)<<endl;
            res+=((n*(n+1))/2);
            l = r;
        }
        return res;
    }
};
