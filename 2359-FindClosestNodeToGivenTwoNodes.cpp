class Solution {
public:
    vector<int> bfs(const vector<vector<int>>& adjl, int src){
        queue<int> q;
        q.push(src);
        vector<int> res(adjl.size(), -1);
        res[src] = 0;
        vector<bool> v(adjl.size());
        v[src] = true;
        while(!q.empty()){
            auto f = q.front(); q.pop();
            for(const auto& n : adjl[f]){
                //cout<<"can reach "<<n<<" from "<<f<<endl;
                if(!v[n]){
                    v[n] = true;
                    res[n] = res[f]+1;
                    q.push(n);
                }
            }
        }
        return res;
    }
    void print(const vector<int>& a){
        //for(const auto& d : a) cout<<d<<" "; cout<<endl;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<vector<int>> adjl(edges.size());
        for(int i = 0; i<edges.size(); i++){
            if(edges[i]==-1) continue;
            adjl[i].push_back(edges[i]);
        }
        auto n1 = bfs(adjl, node1);
        auto n2 = bfs(adjl, node2);
        print(n1); print(n2);
        int res = 1e9;
        int nres = -1;
        for(int i = edges.size()-1; i>=0; i--){
            if(n1[i]!=-1&&n2[i]!=-1){
                if(res>=max(n1[i],n2[i])){
                    res = max(n1[i],n2[i]);
                    nres = i;
                }
            }
        }
        return nres;
    }
};
