class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2) return {};
        map<int, int> m;
        for(const auto& c : changed) m[c]++;
        auto cm = m;
        int found = 0;
        vector<int> res;
        while(found<(n/2)){
            auto f = m.begin()->first;
            m[f]--;
            if(!m[f]) m.erase(f);
            cout<<f<<endl;
            if(m.find(f*2)==m.end()) return {};
            res.push_back(f);
            m[2*f]--;
            if(!m[2*f]) m.erase(2*f);
            found++;
        }
        return res;
    }
};
