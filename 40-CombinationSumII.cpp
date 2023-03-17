class Solution {
public:
    void dfs(int curr, vector<int>& p, int l, vector<vector<int>>& res){
        if(!l){
            res.push_back(p); return;
        }
        if(l<0) return;
        for(int i = curr; i<c.size(); i++){
            //do not pick the same number from this curr; 
            //the next curr will do that if required
            //<1, 1, 2, 5> and t = 3
            //pick the first 1 but not the second 
            //the first one will use the 2 but not the second 
            //<1, 2> and <1, 2> duplicates can be avoided
            if(!(i>curr&&c[i]==c[i-1])){
                p.push_back(c[i]);
                dfs(i+1, p, l-c[i], res);
                p.pop_back();
            }
        }
    }
    vector<int> c; int t;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        c = candidates;
        t = target;
        vector<int> p;
        sort(c.begin(), c.end());
        vector<vector<int>> res;
        dfs(0, p, t, res);
        return res;
    }
};
