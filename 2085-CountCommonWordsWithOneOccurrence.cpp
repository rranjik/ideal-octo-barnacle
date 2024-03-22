class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> a;
        unordered_map<string, int> b;
        unordered_set<string> s;
        for(const auto& w : words1) {
            s.insert(w);
            a[w]++;
        }
        for(const auto& w : words2) {
            s.insert(w);
            b[w]++;
        }
        
        int res = 0;
        for(const auto& w : s){
            if(a.find(w)!=a.end()&&b.find(w)!=b.end()&&a[w]==1&&b[w]==1)
                res++;
        }
        return res;
    }
};
