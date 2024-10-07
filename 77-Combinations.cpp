class Solution {
public:
    vector<vector<int>> res;
    void dfs(int pos, vector<int>& cur){
        if(cur.size()==k){
            res.push_back(cur);
            return;
        }
        for(int i = pos; i<=n/*-(k-cur.size)*/; i++){
            cur.push_back(i);
            dfs(i+1, cur);
            cur.pop_back();
        }
    }
    int n;
    int k; 
    vector<vector<int>> combine(int n, int k) {
        this->n = n; this->k = k;
        vector<int> cur;
        dfs(1, cur);
        return res;
    }
};
