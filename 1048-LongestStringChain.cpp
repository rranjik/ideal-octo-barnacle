class Solution {
public:
    int dp(string s){
        //cout<<"dp("<<s<<")"<<endl;
        if(lengths[s]!=-1) return lengths[s];
        if(!s.length()) {
            lengths[s] = 0;
            return 0;
        }
        int res = 1;
        for(int i = 0; i<s.length(); i++){
            string ns;
            ns+=s.substr(0, i);
            ns+=s.substr(i+1, string::npos);
            //cout<<"looking @ "<<ns<<" of "<<s<<" for i = "<<i<<endl;
            if(wrds.find(ns)!=wrds.end()){
                res = max(res, dp(ns)+1);
            }
        }
        lengths[s] = res;
        return res;
        
    } 
    set<string> wrds;
    unordered_map<string, int> lengths;
    int longestStrChain(vector<string>& words) {
        for(const auto& w : words){
            lengths.insert({w, -1});
            wrds.insert(w);
        }
        for(auto it = wrds.rbegin(); it!=wrds.rend(); it++){
            dp(*it);
        }
        int res = 0;
        for(const auto& it : lengths){
            res = max(res, it.second);
        }
        return res;
    }
};
