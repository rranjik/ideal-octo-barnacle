class Solution {
public:
    void dfs(int s, vector<int>& cc){
        v[s] = true;
        for(const auto& a : adjl[s]){
            if(!v[a]) {
                cc.push_back(a);
                dfs(a, cc);
            }
        }
    }
    vector<bool> v;
    vector<vector<int>> adjl;
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        adjl = vector<vector<int>>(s.length());
        for(const auto& p : pairs){
            adjl[p[0]].push_back(p[1]);
            adjl[p[1]].push_back(p[0]);
        }
        int n = s.length();
        v = vector<bool>(n);
        string res = s;
        for(int i = 0; i<n; i++){
            if(!v[i]){
                vector<int> cc;
                cc.push_back(i);
                dfs(i, cc);
                string inter;
                sort(begin(cc), end(cc));
                for(const auto& j : cc){
                    inter+=s[j];
                }
                sort(begin(inter), end(inter));
                for(int j = 0; j<cc.size(); j++){
                    res[cc[j]] = inter[j];
                }
            }
        }
        return res;
    }
};
