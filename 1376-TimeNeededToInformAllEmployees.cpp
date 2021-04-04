class Solution {
public:
    unordered_map<int, vector<int>> adjl;
    int wc = 0;
    void dfs(int r, int i){
        //cout<<r<<" was informed at time "<<i<<endl;
        wc = max(i, wc);
        if(i>=wc){
            //cout<<"wc incremented from "<<wc;
            wc+=it[r];
            //cout<<" to "<<wc<<" by "<<it[r]<<endl;
        }
        for(const auto& dr : adjl[r]){
            dfs(dr, i+it[r]);
        }
    }
    vector<int> it;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        it = informTime;
        int r = 0;
        for(int i = 0; i<manager.size(); i++){
            if(manager[i]==-1) r = i;
            else {
                adjl[manager[i]].push_back(i);
            }
        }
        dfs(r, 0);
        return wc;
    }
};
