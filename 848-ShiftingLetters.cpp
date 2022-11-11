class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        for(int i = shifts.size()-2; i>=0; i--){
            shifts[i] = (shifts[i]+shifts[i+1])%26;
        }
        string res;
        for(int i = 0; i<shifts.size(); i++){
            auto n = S[i]-'a';
            n+=shifts[i];
            n%=26;
            char nn = static_cast<char>('a'+n);
            res.push_back(nn);
        }
        return res;
    }
};
