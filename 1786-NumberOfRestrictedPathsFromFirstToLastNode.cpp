class Solution {
public:
    int dfs(int v, int dflntov){
        if(c.find(v)!=c.end()) return c[v];
        if(v==n) return 1;
        int res{};
        for(const auto& c : adjl[v]){
            if(dfln[c.second]<dflntov){
                res+=(dfs(c.second, dfln[c.second])%mod);
                res%=mod;
            }
            
        }
        return c[v] = res;
    }
    using pii = pair<int, int>;
    unordered_map<int, vector<pii>> adjl;
    int n;
    int mod;
    unordered_map<int, int> c;
    vector<int> dfln;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        mod = 1e9+7;
        this->n = n;
        dfln = vector<int>(n+1, 1e9);
        for(int i = 0; i<edges.size(); i++){
            auto u = edges[i][0];
            auto v = edges[i][1];
            auto w = edges[i][2];
            adjl[u].push_back({w, v});
            adjl[v].push_back({w, u});
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, n});
        vector<bool> vs(n+1);
        while(!pq.empty()){
            auto t = pq.top();pq.pop();
            auto v = t.second;
            if(vs[v]) continue;
            vs[v] = true;
            auto d = t.first;
            //cout<<"v = "<<v<<" d = "<<d<<endl;
            dfln[v] = d;
            for(const auto& c : adjl[v]){
                if(dfln[c.second]>dfln[v]+c.first){
                    if(vs[c.second]) continue;
                    dfln[c.second] = dfln[v]+c.first;
                    pq.push({dfln[v]+c.first, c.second});
                }
            }
        }
        //for(int i = 0; i<dfln.size(); i++){
        //    cout<<"i = "<<i<<"; dfln = "<<dfln[i]<<endl;
        //}
        auto res = dfs(1, dfln[1]);
        return res;
    }
};
