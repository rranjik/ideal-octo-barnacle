class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqr;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqc;
        int m = rowSum.size();
        if(!m) return {};
        int n = colSum.size();
        for(int i = 0; i<rowSum.size(); i++){
            int v = rowSum[i];
            pqr.push({v, i});
        }
        for(int i = 0; i<colSum.size(); i++){
            int v = colSum[i];
            pqc.push({v, i});
        }
        vector<vector<int>> res(m , vector<int>(n));
        while(!pqr.empty()||!pqc.empty()){
            auto r = pqr.top(); pqr.pop();
            auto c = pqc.top(); pqc.pop();
            auto i = r.second;
            auto j = c.second;
            auto v = min(r.first, c.first);
            r.first-=v;
            c.first-=v;
            if(r.first) pqr.push(r);
            if(c.first) pqc.push(c);
            res[i][j] = v;
        }
        return res;
    }
};
