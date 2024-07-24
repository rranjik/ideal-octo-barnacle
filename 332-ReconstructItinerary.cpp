class Solution {
public:
    bool dfs(string at, int n, vector<string>& res){
        cout<<"at "<<at<<endl;
        if(n==0) return true;
        if(m.find(at)==m.end()) return false;
        for(int i = 0; i<m[at].size(); i++){
            cout<<"i = "<<i<<endl;
            if(u[at][i]) continue;
            u[at][i] = true;
            cout<<"trying "<<i<<" flight from "<<at<<endl;
            auto nex = *(m[at].begin()+i);
            auto ores = res;
            auto oat = at;
            res.insert(res.end(), nex.begin()+1, nex.end());
            at = res.back();
            if(dfs(at, n-1, res)) return true;
            cout<<"retured "<<endl;
            res = ores;
            at = oat;
            u[at][i] = false;
            cout<<"continuing "<<endl;
        }
        return false;
    }
    map<string, vector<vector<string>>> m;
    map<string, vector<bool>> u;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        for(int i = 0; i<tickets.size(); i++){
            auto t = tickets[i];
            auto b = t[0];
            m[b].push_back(t);
            u[b].push_back(false);
        }
        for(auto& [s, its]: m) sort(its.begin(), its.end());
        string at = "JFK";
        vector<string> res{"JFK"};
        dfs(at, n, res);
        return res;
    }
};
