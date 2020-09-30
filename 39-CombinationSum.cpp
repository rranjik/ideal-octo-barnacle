class Solution {
public:
    void dfs(vector<int> cl, int s, int rs){
        //cout<<"rs = "<<rs<<"; s = "<<s<<endl;
        if(rs<0) return;
        if(rs==0) {
            res.push_back(cl);
        }
        for(int i = s; i<c.size(); i++){
            cl.push_back(c[i]);
            dfs(cl, i, rs-c[i]);
            cl.pop_back();
        }
    }
    vector<int> c;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        c = candidates;
        vector<int> cl;
        dfs(cl, 0, target);
        return  res;
    }
};
