class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> c(3);
        for(const auto& a : stones){
            c[a%3]++;
        }
        if(min(c[1],c[2])==0){
            return max(c[1], c[2])>2&&(c[0]%2!=0);
        }
        return abs(c[1]-c[2])>2||c[0]%2==0;
    }
};
