class RowStat{
public:
    int ns;
    int i;
    RowStat(int _ns, int _i):ns(_ns), i(_i){}
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        if(!mat.size())return res;
        auto comp = [](const RowStat& rs1, const RowStat& rs2){
            if(rs1.ns==rs2.ns){
                return rs1.i<rs2.i;
            }
            return rs1.ns<rs2.ns;
        };
        priority_queue<RowStat, vector<RowStat>, decltype(comp)> q(comp);
        for(int i = 0; i<mat.size(); i++){
            int ns = 0;
            for(int j = 0; j<mat[0].size()&&mat[i][j]==1; j++){
                ns++;
            }
            auto rs = RowStat(ns, i);
            q.push(rs);
            if(q.size()>k) q.pop();
        }
        while(!q.empty()){
            auto rs = q.top();
            q.pop();
            res.push_back(rs.i);
        }
        reverse(begin(res), end(res));
        return res;
    }
};
