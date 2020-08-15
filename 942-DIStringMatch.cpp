class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<int> res(n+1, -1);
        int st = n;
        for(int i = 0; i<n; i++){
            if(s[i]=='D') {res[i] = st; st--;}
        }
        st = 0;
        for(int i = 0; i<n+1; i++){
            if(res[i] == -1) {res[i]=st; st++;}
        }
        return res;
    }
};
