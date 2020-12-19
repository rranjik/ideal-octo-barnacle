class Solution {
public:
    //vector<string> wordBreak(string s, vector<string>& wordDict) {
    //    vector<string> res;
    //    unordered_set<string> S(begin(wordDict), end(wordDict));
    //    stack<pair<string, int>> stk;
    //    stk.push({"", 0});
    //    int L = s.length();
    //    while(!stk.empty()){
    //        auto n = stk.top();
    //        cout<<"popped n = "<<n.second<<endl;
    //        stk.pop();
    //        if(n.second==L){
    //            n.first.pop_back();
    //            res.push_back(n.first);
    //        }
    //        for(int i = 1; i<L-n.second+1; i++){
    //            auto part = s.substr(n.second, i);
    //            cout<<"part = "<<part<<endl;
    //            if(S.find(part)!=S.end()){
    //                cout<<"pushing = "<<n.second+i<<endl;
    //                stk.push({n.first+part+" ", n.second+i});
    //            }
    //        }
    //    }
    //    return  res;
    //
    unordered_set<string> S;
    unordered_map<int, vector<string>> m;
    vector<string> dp(int i){
        if(m.find(i)!=m.end()) return m[i];
        vector<string> res;
        if(i==L){
            m[i] = {""};
            return {""};
        }
        for(int j = 1; j<L-i+1; j++){
            auto part = searchWord.substr(i, j);
            //cout<<"part = "<<part<<endl;
            if(S.find(part)!=S.end()){
                //cout<<"found! "<<endl;
                auto r = dp(i+j);
                for(const auto& p :r){
                    res.push_back(part+(p==""?"":(string(" ")+p)));
                }
            }
        }
        m[i] = res;
        return res;
    }
    string searchWord;
    int L;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->searchWord = s;
        L = searchWord.length();
        S = unordered_set(begin(wordDict), end(wordDict));
        return dp(0);
    }
};
