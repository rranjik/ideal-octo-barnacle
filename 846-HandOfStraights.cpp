class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> f;
        for(const auto& c : hand){
            f[c]++;
        }
        while(f.size()){
            int c = f.begin()->first;
            f[c]--;
            if(!f[c]) f.erase(c);
            int w = W-1;
            while(w){
                int n = c+1;
                if(f.find(n)==f.end()) return false;
                else {
                    f[n]--;
                    if(!f[n]) f.erase(n);
                    c = n;
                }
                w--;
            }
        }
        return true;
    }
};
