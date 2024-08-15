lass Solution {
public:
    long long appealSum(string s) {
        vector<int> p(26, -1);
        long long endi = 0;
        long long res = 0;
        for(int i= 0; i<s.size(); i++){
            int c = s[i]-'a';
            //old ending here extending
            //new ending here 
            endi = endi + (i-p[c]);
            p[c] = i;
            res = res + endi;
        }
        return res;
    }
};
