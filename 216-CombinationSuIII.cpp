class Solution {
public:
    void csdfs(const int k, const int level, const int n, vector<int>& out, vector<vector<int>>& res){
        if(n<0||k<0)
            return;
        if(n==0 && k==0){
            res.push_back(out);
            return;
        }
        for(int i =level; i<10; i++){
            out.push_back(i);
            csdfs(k-1, i+1, n-i, out, res);
            out.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> out;
        csdfs(k, 1, n, out, res);
        return res;
    }
};
