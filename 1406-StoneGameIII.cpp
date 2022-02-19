class Solution {
public:
    int dfs(int pick){
        if(pick>=s.size()) return 0;
        if(c.find(pick)!=c.end()) return c[pick];
        int sum{};
        int res = numeric_limits<int>::min();
        for(int i = 0; i<3&&pick+i<s.size(); i++){
            sum+=s[pick+i];
            res = max(res, sum-dfs(pick+i+1));
        }
        return c[pick]=res;
    }
    vector<int> s;
    unordered_map<int, int> c;
    string stoneGameIII(vector<int>& stoneValue) {
        s = stoneValue;
        auto res = dfs(0);
        if(res<0) return "Bob";
        if(res==0) return "Tie";
        else return "Alice";
    }
};
