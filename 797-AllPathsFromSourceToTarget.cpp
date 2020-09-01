class Solution {
public:
    int n;
    vector<vector<int>> res;
    void dfs(int s, vector<int> cp, const vector<vector<int>>& adjl){
        if(s==n-1){
            res.push_back(cp);
            return;
        }
        for(int i = 0; i<adjl[s].size(); i++){
            cp.push_back(adjl[s][i]);
            dfs(adjl[s][i], cp, adjl);
            cp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> cp(1, 0);
        dfs(0, cp, graph);
        return res;
    }
};
