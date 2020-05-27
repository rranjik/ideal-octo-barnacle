class Solution {
public:
    string w;
    void dfs(int s, string c, vector<string>& res){
        if(s>= w.size()){
            res.push_back(c);
            return;
        }
        for(int i = 0; i<=w.size()-s; i++){
            if(!i){
                auto cp = c;
                cp+=w[s];
                dfs(s+1, cp, res);
            }else{
                auto cp = c;
                cp+=to_string(i);
                cp+=w[s+i];
                dfs(s+i+1, cp, res);
            }
        }
    }
    vector<string> generateAbbreviations(string word) {
        this->w = word;
        vector<string> res;
        string c;
        dfs(0, c, res);
        return res;
    }
};
