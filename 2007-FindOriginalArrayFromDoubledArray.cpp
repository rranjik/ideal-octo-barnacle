class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2) return {};
        unordered_map<int, int> f;
        for(const auto& n : changed){
            f[n]++;
        }
        sort(changed.begin(), changed.end());
        vector<int> res;
        for(int i =0; i<changed.size(); i++){
            auto v = changed[i];
            if(f.find(v)!=f.end()){
                if(f.find(2*v)!=f.end()){
                    res.push_back(v);
                    f[v]--;
                    f[2*v]--;
                    if(!f[v]) f.erase(v);
                    if(!f[2*v]) f.erase(2*v);
                }else{
                    return {};
                }
            }
        }
        return res;
    }
};
