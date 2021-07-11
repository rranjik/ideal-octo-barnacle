class Solution {
public:
    using pii = pair<int, int>;
    pii findextent(int i, const string& ss){
        if(i>=ss.length()){
            return {-1, -1};
        }
        int start = i;
        int end = i+1;
        while(end<ss.length()&&ss[start]==ss[end]) end++;
        return {start, end};
    }
    void RollingLengthEncode(const string& ss, vector<char>& key, vector<int>& keycount){
        int i = 0;
        while(i<ss.length()){
            auto e = findextent(i, ss);
            key.push_back(ss[e.first]);
            keycount.push_back(e.second-e.first);
            i = e.second;
        }
    }
    int expressiveWords(string S, vector<string>& words) {
        vector<char> SKey;
        vector<int> SKeyc;
        RollingLengthEncode(S, SKey, SKeyc);
        int res{};
        for(const auto& w : words){
            vector<char> wkey;
            vector<int> wkeyc;
            RollingLengthEncode(w, wkey, wkeyc);
            if(wkey==SKey){
                bool matches = true;
                for(int i = 0; matches&&i<SKey.size(); i++){
                    auto sc = SKeyc[i]; //count in s
                    auto wc = wkeyc[i]; //count in w
                    if(sc<wc){
                        matches = false;
                    }
                    if(sc<3){
                        if(wc!=sc) matches = false;
                    }
                }
                if(matches) res++;
            }
        }
        return res;
    }
};
