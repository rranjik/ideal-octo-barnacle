class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> al(n, vector<int>());
        vector<int> res;
        for(const auto& e : edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for(int i = 0; i< n; i++){
            if(al[i].size()==1||al[i].size()==0)
                q.push(i);
        }
        int proc = n;
        while(!q.empty()){
            int sq = q.size();
            if(proc==2||proc==1){
                int sq1 = q.size();
                for(int i = 0; i<sq1; i++){
                    res.push_back(q.front());
                    q.pop();
                }
                return res;
            }
            for(int i = 0; i<sq; i++){
                auto f = q.front();
                cout<<"processing "<<f<<endl;
                proc--;
                q.pop();
                auto p = al[f][0];
                al[f] = vector<int>();
                al[p].erase(remove(al[p].begin(), al[p].end(), f), al[p].end());
                if(al[p].size()==1)
                    q.push(p);
            }
        }
        return res;
    }
};
