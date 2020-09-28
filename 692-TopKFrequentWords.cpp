class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> f;
        for(const auto& w : words){
            f[w]++;
        }
        map<int, vector<string>, greater<int>> ifreq;
        for(auto it : f){
            ifreq[it.second].insert(
                upper_bound(ifreq[it.second].begin(),
                            ifreq[it.second].end(),
                            it.first), it.first);
        }
        int e = 0;
        vector<string> res;
        for(auto it = ifreq.begin(); e<k&&it!=ifreq.end(); it++){
            for(const auto w : it->second){
                if(e<k){
                    res.push_back(w);
                    e++;
                }
                else break;
            }
        }
        return  res;
    }
};
