class Solution {
public:
    double res{};
    bool done{false};
    void dfs(int r, int p, int t){
        cout<<"at "<<r<<" with prob 1/"<<p<<endl;
        v[r] = true;
        if(r==target) {
            auto d = 0;
            for(const auto& c : adjl[r]) if(!v[c]) d++;
            if(t==tt){
                res = (1.0/(double)(p));
                done = true;
            }
            else if(t<=tt&&!d){
                res = (1.0/(double)(p));
                done = true;
            }
        }
        //if(!done){
            auto d = 0;
            for(const auto& c : adjl[r]) if(!v[c]) d++;
            for(auto& c : adjl[r]) {
                if(!v[c])
                dfs(c, p*d, t+1);
            }
        //}
    }
    vector<vector<int>> adjl;
    vector<bool> v;
    int target;
    int tt;
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        this->target = target;
        tt = t;
        adjl = vector<vector<int>>(edges.size()+2);
        v = vector<bool>(edges.size()+2);
        for(int i = 0; i<edges.size(); i++){
            adjl[edges[i][0]].push_back(edges[i][1]);
            adjl[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i = 1; i<adjl.size(); i++){
            cout<<i<<"->";
            for(const auto& c : adjl[i]) cout<<c<<"->";
            cout<<endl;
        }
        dfs(1, 1, 0);
        return res;
    }
};
