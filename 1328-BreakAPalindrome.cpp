class Solution {
public:
    string breakPalindrome(string p) {
        if(p.size()<=1) return "";
        int n = p.size();
        int si = -1;
        char s = static_cast<char>('z'+1);
        for(int i = 0; i<(n+1)/2; i++){
            char m = p[n-i-1];
            if(p[i]<s){
                s = p[i];
                si = i;
            }
            if(m!='a'&&i!=n-i-1) {
                p[i] = 'a';
                return p;
            }
        }
        cout<<"si = "<<si<<endl;
        if(p[si]=='a') {
            p[n-si-1]++;
            return p;
        }
        p[si]--;
        return p;
    }
};
