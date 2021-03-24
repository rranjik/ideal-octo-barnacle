class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<int> tc(words.size(), 0);
        unordered_map<string, pair<int, int>> m;
        for(const auto& w : words) m[w].second++;
        bool workleft = true;
        for(int i = 0; workleft&&i<S.length(); i++){
            workleft = false;
            for(auto& it : m){
                if((it).second.first<((it).first.length())){
                    if(S[i]==((it).first)[(it).second.first]) 
                        (it).second.first++;
                }
                if((it).second.first<((it).first.length())) workleft = true;
            }
        }
        int res = 0;
        for(auto& it : m){
            if((it).second.first==(it).first.length()) res+=(it).second.second;
        }
        return res;
    }
};
