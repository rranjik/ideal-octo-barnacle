class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res = code;
        int n = code.size();
        for(int i = 0; i<code.size(); i++){
            if(k>0){
                int r{};
                for(int j = 1; j<=k; j++){
                    auto h = (i+j)%n;
                    r+=code[h];
                }
                res[i] = r;
            }else if(k<0){
                int r{};
                for(int j = 1; j<=abs(k); j++){
                    auto h = (i-j+n)%n;
                    r+=code[h];
                }
                res[i] = r;
            }else {
                res[i] = 0;
            }
        }
        return res;
    }
};
