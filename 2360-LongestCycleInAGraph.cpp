class Solution {
public:
    int bfs(const vector<vector<int>>& adjl, int src, unordered_set<int>& v){
        queue<int> q;
        q.push(src);
        int res = 0;
        while(!q.empty()){
            auto f = q.front(); q.pop();
            for(const auto& n : adjl[f]){
                //cout<<"can reach "<<n<<" from "<<f<<endl;
                if(v.find(n)==v.end()){
                    res++;
                    v.insert(n);
                    q.push(n);
                }
            }
        }
        return res;
    }
    int longestCycle(vector<int>& edges) {
                vector<vector<int>> adjl(edges.size());
        for(int i = 0; i<edges.size(); i++){
            if(edges[i]==-1) continue;
            adjl[i].push_back(edges[i]);
        }
        unordered_map<int, int> indeg;
        unordered_set<int> left;
        for(int i = 0; i<edges.size(); i++){
            left.insert(i);
        }
        for(int i = 0; i<edges.size(); i++){
            if(edges[i]==-1) {
                left.erase(i);
                continue;
            }
            indeg[edges[i]]++;
        }
        int noc = 0;
        auto elim = true;
        while(elim){
            elim = false;
            unordered_set<int> nex;
            for(const auto& i : left){
                nex.insert(i);
                if(indeg.find(i)==indeg.end()){
                    if(edges[i]!=-1){
                        nex.erase(i);
                        //cout<<i<<"->"<<edges[i]<<endl;
                        indeg[edges[i]]--;
                        if(indeg[edges[i]]==0) indeg.erase(edges[i]);
                        elim = true;
                    }
                }
            }
            swap(nex, left);
        }
        int res = -1;
        unordered_set<int> v;
        for(const auto& it : left){
            if(v.find(it)==v.end()){
                auto cc = bfs(adjl, it, v);
                res = max(res, cc);
            }
        }
        return res;
        return left.size()<=1?-1:left.size();
    }
};
