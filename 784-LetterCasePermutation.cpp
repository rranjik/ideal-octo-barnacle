class Solution {
public:
    void dfs(int i, string c, set<string>& res){
        if(i==len){
            res.insert(c);
            return;
        }
        if(isalpha(s[i])){
            dfs(i+1, c+string(1, tolower(s[i])), res);
            dfs(i+1, c+string(1, toupper(s[i])), res);
        }
        dfs(i+1, c+string(1, s[i]), res);
    }
    int len;
    string s;
    vector<string> letterCasePermutation(string S) {
        len = S.length();
        s = S;
        set<string> res;
        string c;
        dfs(0, c, res);
        vector<string> rres;
        for(const auto& r : res)
            rres.push_back(r);
        return rres;
    }
};
