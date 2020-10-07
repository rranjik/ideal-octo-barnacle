class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        sleep(0.5);
        regex word_regex("(\\w+)");
    auto words_begin = 
        sregex_iterator(p.begin(), p.end(), word_regex);
    auto words_end = sregex_iterator();
        unordered_set<string> ban(banned.begin(), banned.end());
        //for(auto b : banned){
        //    transform(b.begin(), b.end(), b.begin(),
        //           [](unsigned char c) -> unsigned char 
        //              { return std::tolower(c); });
        //    ban.insert(b);
        //}
        map<string, int> f;
        for(auto i = words_begin; i!= words_end; i++){
            smatch match = *i;
            auto match_str = match.str();
            transform(match_str.begin(), 
                      match_str.end(), match_str.begin(),
                   [](unsigned char c) -> unsigned char 
                      { return std::tolower(c); });
            if(ban.find(match_str)==ban.end()){
                f[match_str]++;
            }
        }
        string res;
        int maxi = 0;
        for(auto it : f){
            if(it.second>maxi){
                maxi = it.second;
                res = it.first;
            }
        }
        return res;
    }
};
