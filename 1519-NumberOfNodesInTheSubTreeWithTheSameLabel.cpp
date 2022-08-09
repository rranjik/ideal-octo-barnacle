class Solution {
public:
    vector<bool> v;
    vector<int> dfs(int s, vector<int> fp, const vector<vector<int>>& adjl){
        vector<int> r(26);
        v[s] = true;
        int here = 1;
        r[l[s]-'a']++;
        for(const auto& c : adjl[s]){
            if(!v[c]){
                auto sub = dfs(c, fp, adjl);
                for(int i = 0; i<26; i++) r[i]+=sub[i];
            }
        }
        res[s] = r[l[s]-'a'];
        return r;
    }
    vector<int> res;
    string l;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        l = labels;
        v = vector<bool>(n, false);
        res = vector<int>(n, 0);
        vector<vector<int>> adjl(n);
        for(const auto& e : edges){
            adjl[e[0]].push_back(e[1]);
            adjl[e[1]].push_back(e[0]);
        }
        vector<int> f(26);
        dfs(0, f, adjl);
        return res;   
    }
};
