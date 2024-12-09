class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> p;
        unordered_set<int> l;
        unordered_map<int, int> lm;
        for(const auto& m : matches){
            p.insert(m[0]);
            p.insert(m[1]);
            lm[m[1]]++;
        }
        set<int> w;
        set<int> k;
        for(const auto& i : p){
            if(lm.find(i)==lm.end()){
                w.insert(i);
            }else if(lm[i]==1){
                k.insert(i);
            }
        }
        vector<int> ww(w.begin(), w.end());
        vector<int> kk(k.begin(), k.end());
        return {ww, kk};
    }
};
