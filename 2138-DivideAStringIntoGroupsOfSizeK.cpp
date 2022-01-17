class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        for(int i = 0; i<s.size();){
            int K = k;
            string r;
            while(K&&i<s.size()){
                r.push_back(s[i]);
                i++;
                K--;
            }
            while(K){
                r.push_back(fill);
                K--;
            }
            res.push_back(r);
        }
        return res;
    }
};
