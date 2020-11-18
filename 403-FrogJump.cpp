namespace std{
    template<>
    struct hash<pair<int, int>>{
        size_t operator()(const pair<int, int>& p)const{
        return (hash<int>()(p.first)^0x29434830)^
        (hash<int>()(p.second)^0x2948309);
        }
    };
}
class Solution {
public:
    unordered_map<pair<int, int>, bool> ca;
    bool dfs(int c, int l){
        auto coor = pair<int, int>(c, l);
        if(ca.find(coor)!=ca.end()) return ca[coor];
        if(c == t) {
            ca[coor] = true;
            return true;
        }
        bool res = false;
        for(int i = l-1; !res&&i<=l+1; i++){
            if(i>0&&s.find(c+i)!=s.end()){
                res |= dfs(c+i, i);
            }
        }
        ca[coor] = res;
        return res;
    }
    unordered_set<int> s;
    int t;
    bool canCross(vector<int>& stones) {
        t = stones[stones.size()-1];
        for(const auto& st :stones)
           s.insert(st);
        return dfs(0, 0);
    }
};
