class Solution {
public:
    map<int, vector<int>> adjl;
    vector<int> res;
    map<int, bool> v;
    void dfs(int src){
        v[src] = true;
        res.push_back(src);
        for(const auto& p : adjl[src]){
            if(!v[p]){
                dfs(p);
            }
        }
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        for(int i = 0; i<pid.size(); i++){
            adjl[ppid[i]].push_back(pid[i]);
            v[pid[i]] = false;
        }
        dfs(kill);
        return res;
    }
};
