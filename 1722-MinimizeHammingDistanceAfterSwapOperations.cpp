class Solution {
public:
    vector<vector<int>> adjl;
    void dfs(int i, unordered_multiset<int>& c, vector<int>& ci, const vector<int>& s){
        v[i] = true;
        c.insert(s[i]);
        ci.push_back(i);
        for(const auto& j : adjl[i]){
            if(!v[j]) dfs(j, c, ci, s);
        }
    }
    vector<bool> v;
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        auto n = source.size();
        //cout<<"n = "<<n<<endl;
        adjl = vector<vector<int>>(n);
        v = vector<bool>(n);
        for(const auto& e : allowedSwaps){
            auto u = e[0]; auto v = e[1];
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        vector<unordered_multiset<int>> cmpts;
        int cmpi = 0;
        vector<int> toc(n);
        for(int i = 0; i<n; i++){
            if(!v[i]) {
                unordered_multiset<int> c;
                vector<int> ci;       
                dfs(i, c, ci, source);
                cmpts.push_back(c);
                for(const auto& j : ci) {
                    toc[j] = cmpi;
                }
                cmpi++;
            }
        }
        int res{};
        //cout<<"number of c = "<<cmpts.size()<<endl;
        for(int i = 0; i<n; i++){
            auto ci = toc[i];
            auto& c = cmpts[ci];
            //cout<<"source["<<i<<"] = "<<source[i]<<"; ";
            //cout<<"target["<<i<<"] = "<<target[i]<<": ";
            //for(const auto& it : c) cout<<it<<" ";
            //cout<<endl;
            if(c.find(target[i])!=c.end()) {
                //cout<<"found!"<<endl;
                auto it = c.find(target[i]);
                c.erase(it);
            }
            else res++;
        }
        return res;
    }
};
