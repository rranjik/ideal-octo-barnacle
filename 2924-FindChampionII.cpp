class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> t(n);
        for(const auto& e : edges){
            int u = e[0];
            int v = e[1];
            t[v]++;
        }
        int res = -1;
        for(int i = 0; i<n; i++){
            if(t[i]==0) {
                if(res==-1) res = i;
                else return -1;
            }
        }
        return res;
    }
};
