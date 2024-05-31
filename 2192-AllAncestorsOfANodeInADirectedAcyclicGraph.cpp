class Solution {
public:
    void dfs(int s, unordered_set<int>& r, const vector<vector<int>>& adjl){
        cout<<"at "<<s<<endl;
        vi[s] = true;
        for(const auto& n : adjl[s]){
            r.insert(n);
            unordered_set<int> ch;
            if(!vi[n]){
                dfs(n, ch, adjl);
                inter[n] = ch;
                for(const auto& vv : ch)
                    r.insert(vv);
            }else{
                for(const auto& vv : inter[n])
                    r.insert(vv);
            }
        }
    }
    vector<int> vi;
    vector<unordered_set<int>> inter;
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vi = vector<int>(n);
        inter = vector<unordered_set<int>>(n);
        vector<vector<int>> adjl(n);
        unordered_map<int, int> in;
        for(const auto& e : edges){
            adjl[e[1]].push_back(e[0]);
        }
        vector<vector<int>> res(n);
        for(int i = 0; i<n; i++){
            if(vi[i]){
                unordered_set<int> rres = inter[i];
                vector<int> b(rres.begin(), rres.end());
                sort(b.begin(), b.end());
                res[i] = b;
                inter[i] = rres;
                continue;
            }
            cout<<" dfsing "<<i<<endl;
            unordered_set<int> rres;
            dfs(i, rres, adjl);
            vector<int> b(rres.begin(), rres.end());
            sort(b.begin(), b.end());
            inter[i] = rres;
            res[i] = b;
        }
        return res;
    }
};
