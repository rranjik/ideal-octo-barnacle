class Solution {
public:
    int n;
    void dfs(int i, int k, vector<int>& curr, vector<vector<int>>& res){
        if(!k){
            res.push_back(curr);
            return;
        }
        //cout<<"i = "<<i<<"; k = "<<k<<endl;
        //int j = 0;
        for(int j = i; /*((n-j+1)>=k-1)&&*/j<=n; j++){
            curr.push_back(j);
            dfs(j+1, k-1, curr, res);
            curr.pop_back();
        }
        //cout<<"i = "<<i<<" to "<<j-1<<endl;
    }
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        vector<vector<int>> res;
        vector<int> c;
        dfs(1, k, c, res);
        return res;
    }
};
