class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        unordered_map<int, int> degm;
        vector<vector<int>> adjl(n);
        vector<bool> v(n);
        for(const auto& e : edges){
            degm[e[0]]++;
            degm[e[1]]++;
            adjl[e[0]].push_back(e[1]);
            adjl[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for(const auto& [i, deg] : degm){
            if(deg==1){
                v[i] = true;
                q.push(i);
            }
        }
        vector<vector<int>> l;
        while(!q.empty()){
            auto s = q.size();
            for(int i = 0; i<s; i++){
                auto t = q.front(); q.pop();
                cout<<"popped "<<t<<endl;
                for(const auto& j : adjl[t]){
                    cout<<"seeing "<<j<<" with "<<degm[j]<<endl;
                    degm[j]--;
                    if(degm[j]==1){
                        v[j] = true;
                        q.push(j);
                    }
                }
            }
        }
        vector<int> res(n);
        vector<bool> vv(n);
        for(int i = 0; i<n; i++){
            if(!v[i]) {
                q.push(i);
                vv[i] = true;
                res[i] = 0;
            }
        }
        int lvl = 1;
        while(!q.empty()){
            auto s = q.size();
            for(int i = 0; i<s; i++){
                auto t = q.front(); q.pop();
                cout<<"at "<<t<<endl;
                for(const auto& j : adjl[t]){
                    if(!vv[j]){
                        res[j] = lvl;
                        vv[j] = true;
                        q.push(j);
                    }
                }
            }
            lvl++;
        }
        return res;
    }
};
