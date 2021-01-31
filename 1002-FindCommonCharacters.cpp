class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<vector<int>> freqs(A.size(), vector<int>(26));
        for(int i = 0; i<A.size(); i++){
            for(int j = 0; j<A[i].size(); j++){
                freqs[i][A[i][j]-'a']++;
            }
        }
        vector<string> res;
        for(char i = 'a'; i<='z'; i++){
            int m = numeric_limits<int>::max();
            for(int j = 0; j<freqs.size(); j++){
                if(m>freqs[j][i-'a']) m = freqs[j][i-'a'];
            }
            while(m){
                res.push_back(string(1, i));
                m--;
            }
        }
        return res;
    }
};
