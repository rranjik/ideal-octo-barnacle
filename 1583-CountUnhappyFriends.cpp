class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        unordered_map<int, unordered_map<int, int>> p;
        
        for(int i = 0; i<preferences.size(); i++){
            auto pi = preferences[i];
            for(int j = 0; j<pi.size(); j++){
                //cout<<"adding "<<preferences[i][j]<<" at "<<j<<" for "<<i<<endl;
                p[i].insert({preferences[i][j], j});
            }
        }
            
        unordered_map<int, int> pp;
        for(int i = 0; i<pairs.size(); i++){
            pp[pairs[i][0]] = pairs[i][1];
            pp[pairs[i][1]] = pairs[i][0];
        }
        
        int res{};
        for(int i = 0; i<n; i++){
            auto x = i;
            auto y = pp[x];
            auto yloc = p[x][y];
            //cout<<"considering "<<i<<" paired with "<<y<<" at "<<yloc<<endl;
            for(int j = 0; j<yloc; j++){
                auto u = preferences[x][j];
                auto xsprefforu = j;
                auto usprefforx = p[u][x];
                auto v = pp[u];
                auto uspartpref = p[u][v];
                //cout<<"u "<<u<<" is paire with "<<v<<" usprefforx = "<<usprefforx<<" uspartpref = "<<uspartpref<<endl;
                if(usprefforx<uspartpref) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
