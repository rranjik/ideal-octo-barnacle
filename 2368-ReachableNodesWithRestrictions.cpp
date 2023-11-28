class Solution {
public:
    unordered_set<int> r;
    vector<bool> v;
    int res = 0;
    void dfs(int s){
        if(r.find(s)!=r.end()) 
            return;
        res++;
        v[s] = true;
        for(const auto& c : adjl[s]){
            if(!v[c]){
                dfs(c);
            }
        }
    }
    vector<vector<int>> adjl;
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        r = unordered_set<int>(restricted.begin(), restricted.end());
        adjl = vector<vector<int>>(n);
        v = vector<bool>(n);
        for(const auto& e : edges){
            adjl[e[0]].push_back(e[1]);
            adjl[e[1]].push_back(e[0]);
        }
        dfs(0);
        return res;
    }
};
