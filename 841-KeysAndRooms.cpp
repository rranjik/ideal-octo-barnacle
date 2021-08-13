class Solution {
public:
    void dfs(int src, vector<bool>& v, const vector<vector<int>>& adjl){
        cout<<"in room "<<src<<endl;
        v[src] = true;
        for(const auto k : adjl[src]){
            if(!v[k]) dfs(k, v, adjl);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<vector<int>> adjl(rooms.size());
        for(int i = 0; i<rooms.size(); i++){
            for(int j = 0; j<rooms[i].size(); j++){
                adjl[i].push_back(rooms[i][j]);
            }
        }
        
        vector<bool> v(rooms.size());
        dfs(0, v, adjl);
        for(const auto& r : v){
            if(!r) return false;
        }
        return true;
    }
};
