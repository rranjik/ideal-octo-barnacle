class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> d(begin(wordList), end(wordList));
        queue<vector<string>> q; q.push({beginWord});
        vector<vector<string>> res;
        unordered_set<string> v;
        while(!q.empty()){
            for(const auto& w : v) if(d.find(w)!=d.end()) d.erase(d.find(w));
            auto len = q.size();
            for(int k = 0; k<len; k++){
                auto p = q.front(); q.pop();
                //cout<<"p = ";
                //for(const auto& w : p) cout<<w<<"-";
                //cout<<endl;
                auto last = p.back();
                for(int i = 0; i<last.length(); i++){
                    for(char j = 'a'; j<='z'; j++){
                        auto l = last;
                        l[i] = j;
                        if(d.find(l)!=d.end()){
                            v.insert(l);
                            p.push_back(l);
                            //cout<<"pushing ";
                            //for(const auto& w : p) cout<<w<<"-"; cout<<endl;
                            if(l==endWord){
                                res.push_back(p);
                            }else{
                                q.push(p);
                            }
                            p.pop_back();
                        }
                    }
                }
            }
        }
        return res;
    }
};
