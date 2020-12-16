class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> S(begin(words), end(words));
        vector<string> res;
        for(const auto& w : S){
            cout<<w<<" ";
        }
        cout<<endl;
        for(auto w : S){
            if(w.length()==0) continue;
            stack<int> stk;
            stk.push(0);
            //unordered_set<int> seen;
            auto L = w.length();
            while(!stk.empty()){
                auto n = stk.top();
                stk.pop();
                if(n==L) {
                    res.push_back(w);
                    break;
                }
                for(int j = 1; j<L-n+1; j++){
                    auto part = w.substr(n, j);
                    if(S.find(part)!=S.end()&&/*(seen.find(n+j)==seen.end())&&*/
                      !(n==0&&j==L)){
                        stk.push(n+j);
                        //seen.insert(n+j);
                    }
                }
            }
        }
        return res;
    }
};
