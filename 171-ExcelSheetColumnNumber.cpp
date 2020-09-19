class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        unsigned long long p = 1;
        for(int i = s.length()-1; i>=0; i--){
            int n = (int)(s[i]-'A'+1);
            cout<<"n = "<<n<<endl;
            ret += (p*n);
            p*=26;
        }
        return ret;
    }
};
