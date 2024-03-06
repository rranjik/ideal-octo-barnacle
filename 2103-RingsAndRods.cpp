class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int, unordered_set<char>> r;
        for(int i = 0; i<rings.size(); i++){
            auto c = rings[i];
            i++;
            int p = rings[i]-'0';
            r[p].insert(c);
        }
        int res = 0;
        for(const auto& it : r){
            if(it.second.size()==3) res++;
        }
        return res;
    }
};
