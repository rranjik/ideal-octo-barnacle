class Solution {
public:
    unordered_map<int, unordered_set<int>> c;
    bool exists(int u, int w){
        if(c.find(u)!=c.end()&&c[u].find(w)!=c[u].end()) return true;
        return false;
    }
    vector<bool> v;
    vector<vector<int>> adjl;
    int res{};
    void dfs(int src, int p){
        //cout<<"at "<<src<<" p = "<<p<<endl;
        v[src] = true;
        if(p!=-1&&!exists(src, p)) {
            //cout<<"adding "<<p<<" to "<<src<<endl;
            res++;
        }
        for(const auto& a : adjl[src]){
            if(!v[a]){
                dfs(a, src);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        v = vector<bool>(n, false);
        adjl = vector<vector<int>>(n);
        for(const auto& conn : connections){
            c[conn[0]].insert(conn[1]);
            adjl[conn[0]].push_back(conn[1]);
            adjl[conn[1]].push_back(conn[0]);
        }
        dfs(0, -1);
        return res;
    }
};
