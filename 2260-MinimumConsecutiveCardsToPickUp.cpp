class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> m;
        int res = 1e9;
        for(int i = 0; i<cards.size(); i++){
            int c = cards[i];
            if(m.find(c)==m.end()){
                m[c] = i;
                continue;
            }else{
                res = min(res, i-m[c]+1);
                m[c] = i;
            }
        }
        return res==1e9?-1:res;
    }
};
