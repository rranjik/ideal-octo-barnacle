class Solution {
public:
    void FloydWarshall(vector<vector<int>>& d){
        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
                }
            }
        }
    }
    int n;
    vector<int> bfs(vector<vector<int>>& adjl){
        queue<int> q;
        q.push(0);
        n = adjl.size();
        vector<bool> v(n);
        vector<int> d(n);
        int t = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i<s; i++){
                auto f = q.front();
                q.pop();
                d[f] = t;
                for(const auto& c : adjl[f]){
                    if(!v[c]){
                        v[c] = true;
                        q.push(c);
                    }
                }    
            }
            t++;
        }
        return d;
    }
    void print(vector<vector<int>>& d){
        for(const auto& r : d){
            for(const auto& n : r){
                cout<<n<<" ";
            }
            cout<<endl;
        }
    }
    void print(vector<int>& d){
        for(const auto& r : d)
            cout<<r<<" ";
        cout<<endl;
    }
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& p) {
        n = p.size();
        //vector<vector<int>> d(n, vector<int>(n, 1e9));
        vector<vector<int>> adjl(n);
        for(int i = 0; i< edges.size(); i++){
            auto u = edges[i][0];
            auto v = edges[i][1];
            //d[u][v] = 1;
            //d[v][u] = 1;
            //d[u][u] = 0;
            //d[v][v] = 0;
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        //jjprint(d);
        //FloydWarshall(d);
        auto d = bfs(adjl);
        //print(d);
        //int res = 0;
        //for(int i = 1; i<n; i++){
        //    auto e = (d[i][0]*2-1)/p[i];
        //    auto lo = e*p[i];
        //    auto li = lo+(d[i][0]*2);
        //    res = max(res, li);
        //}
        //return res+1;
        int res = 0;
        for(int i = 1; i<n; i++){
            auto e = (d[i]*2-1)/p[i];
            auto lo = e*p[i];
            auto li = lo+(d[i]*2);
            res = max(res, li);
        }
        return res+1;
    }
};
