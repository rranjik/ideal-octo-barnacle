class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& e, vector<int>& t) {
        vector<vector<int>> adjl(n+1);
        vector<int> in(n+1);
        for(int i = 0; i<e.size(); i++){
            int u = e[i][0];
            int v = e[i][1];
            adjl[u].push_back(v);
            in[v]++;
        }
        queue<int> q;
        for(int i = 1; i<in.size(); i++){
            if(in[i]==0) q.push(i);
        }
        int res = 0;
        vector<int> es(n+1);
        while(!q.empty()){
            auto f = q.front(); q.pop();
            auto l = es[f]+t[f-1];
            //cout<<"learn "<<f<<" in "<<l<<endl;
            res = max(res, l);
            for(const auto& c : adjl[f]){
                es[c] = max(es[c], l);
                in[c]--;
                if(in[c]==0) q.push(c);
            }
        }
        return res;
    }
};
