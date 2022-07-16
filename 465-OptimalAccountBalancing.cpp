class Solution {
public:
    vector<int> b;
    int dfs(int i){
        while(i<b.size()&&!b[i]) i++;
        if(i==b.size()) return 0;
        int res = numeric_limits<int>::max();
        for(int j = i+1; j<b.size(); j++){
            if(b[i]*b[j]<0){
                b[j]+=b[i];
                res = min(res, dfs(i+1)+1);
                b[j]-=b[i];
            }
        }
        return res;
    }
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> m;
        for(const auto& t : transactions){
            m[t[0]]+=t[2];
            m[t[1]]-=t[2];
        }
        for(const auto& it : m){
            if(it.second) b.push_back(it.second);
        }
        return dfs(0);
    }
};
