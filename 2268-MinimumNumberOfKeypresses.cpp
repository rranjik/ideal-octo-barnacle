class Solution {
public:
    int minimumKeypresses(string s) {
        unordered_map<char, int> m;
        map<int, char, greater<int>> d;
        for(const auto& c : s){
            m[c]++;
        }
        for(const auto& [c, f] : m){
            d[f]++;
        }
        vector<int> h;
        for(auto& [f, nc]: d){
            while(nc) {
                h.push_back(f);
                    nc--;
            }
        }
        auto it = h.begin();
        int r = 0;
        for(int i = 0; it!=h.end()&&i<9; i++){
            r += *it;
            it++;
        }
        for(int i = 0; it!=h.end()&&i<9; i++){
            r += (2**it);
            it++;
        }
        for(int i = 0; it!=h.end()&&i<9; i++){
            r += (3**it);
            it++;
        }
        return r;
    }
};
