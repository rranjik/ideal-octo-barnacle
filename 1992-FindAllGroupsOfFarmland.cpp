class Solution {
public:
    vector<vector<bool>> v;
    vector<vector<int>> l;
    void dfs(int i, int j, int& tlx, int& tly,
            int& brx, int& bry){
        if(i<0||i>=m||j<0||j>=n||v[i][j]||!l[i][j]) return;
        cout<<"i = "<<i<<" j = "<<j<<endl;
        v[i][j] = true;
        tlx = min(tlx, i);
        tly = min(tly, j);
        brx = max(brx, i);
        bry = max(bry, j);
        dfs(i+1, j, tlx, tly, brx, bry);
        dfs(i, j+1, tlx, tly, brx, bry);
        dfs(i-1, j, tlx, tly, brx, bry);
        dfs(i, j-1, tlx, tly, brx, bry);
        return;
    }
    int m; int n;
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        using pii = pair<int, int>;
        m = land.size(); 
        n = land[0].size();
        l = land;
        v = vector<vector<bool>>(m, vector<bool>(n));
        vector<vector<int>> res;
        for(int i = 0; i<land.size(); i++){
            for(int j = 0; j<land[i].size(); j++){
                if(!v[i][j]&&l[i][j]){
                    cout<<" i = "<<i<<" j = "<<j<<endl;
                    int tlx = i;
                    int tly = j;
                    int brx = i;
                    int bry = j;
                    dfs(i, j, tlx, tly, brx, bry);
                    res.push_back({tlx, tly, brx, bry});
                } 
            }
        }
        return res;
    }
};
