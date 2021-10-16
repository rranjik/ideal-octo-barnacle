class Solution {
public:
    vector<vector<int>> adjl;
    bool dfs(int src, int& res){
        bool subTreeHasApples = false;
        for(const auto& c : adjl[src]){
            auto thisChildHasApple = dfs(c, res);
            if(thisChildHasApple) res+=2;
            subTreeHasApples|= thisChildHasApple;
        }
        return subTreeHasApples|has[src];
    }
    vector<bool> has;
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        has = hasApple;
        adjl = vector<vector<int>>(edges.size()+1);
        for(int i = 0; i<edges.size(); i++){
            adjl[edges[i][0]].push_back(edges[i][1]);
        }
        int i = 0;
        for(const auto& children : adjl){
            cout<<"I'm "<<i<<". I can reach ";
            for(const auto& c : children) cout<<c<<" ";
            cout<<endl;
        }
        int res{};
        dfs(0, res);
        return res;
    }
};
