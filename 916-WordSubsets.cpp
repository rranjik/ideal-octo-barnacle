class Solution {
public:
    vector<int> count(string s){
        vector<int> res(26);
        for(int i = 0; i<s.size(); i++){
            res[s[i]-'a']++;
        }
        return res;
    }
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> bmaxcount(26);
        for(const auto& b : B){
            auto t = count(b);
            for(int i = 0; i<26; i++)
                bmaxcount[i] = max(bmaxcount[i], t[i]);
        }
        vector<string> res;
        for(const auto& a : A){
            auto t = count(a);
            bool isuni = true;
            for(int i = 0; i<26; i++){
                if(t[i]<bmaxcount[i]) {
                    isuni = false;
                    break;
                }
            }
            if(isuni) res.push_back(a);
        }
        return res;
    }
};
