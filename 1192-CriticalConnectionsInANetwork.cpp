class Solution {
public:
    vector<vector<int>> adjl;
    vector<int> arr;
    vector<bool> vstd;
    int time = 0;
    int _2ec(int v, int p, vector<vector<int>>& res){
        arr[v] = time++;
        vstd[v] = true;
        int dbe = arr[v];
        for(const auto& w : adjl[v]){
            if(!vstd[w])
                dbe = min(dbe, _2ec(w, v, res));
            else if (w!=p)
                dbe = min(dbe, arr[w]);
        }
        if(dbe==arr[v]&&p!=-1){
            res.push_back(vector<int>{v,p});
        }
        return dbe;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adjl = vector<vector<int>>(n);
        vstd = vector<bool>(n, false);
        arr = vector<int>(n, -1);
        for(const auto& c :connections){
            adjl[c[0]].push_back(c[1]);
            adjl[c[1]].push_back(c[0]);
        }
        vector<vector<int>> res;
        _2ec(0, -1, res);
        return res;
    }
};
