class Solution {
public:
    vector<vector<int>> g;
    vector<int> st;
    vector<int> l;
    bool bfs(int n){
        queue<int> q;
        st[n] = 1;
        l[n] = 0;
        q.push(n);
        while(!q.empty()){
            auto f = q.front();
            st[f] = 2;
            q.pop();
            for(const auto& c : g[f]){
                if(l[c]==l[f])
                    return false;
                else if(st[c]==0){
                    st[c]=1;
                    l[c] = l[f]+1;
                    q.push(c);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        g = graph;
        st = vector<int>(g.size(), 0);
        l = vector<int>(g.size(), -1);
        for(int i = 0; i<g.size(); i++){
            if(st[i]!=2){
                if(!bfs(i))
                    return false;
            }
        }
        return true;
    }
};
