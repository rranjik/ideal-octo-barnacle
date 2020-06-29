class Solution {
public:
    
    vector<vector<int>> adjl;
    vector<bool> vstd;
    void cc(int s){
        vstd[s] = true;
        for(const auto& w: adjl[s]){
            if(!vstd[w]){
                cc(w);
            }
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size()<n-1){
            return -1;
        }
        adjl = vector<vector<int>>(n);
        vstd = vector<bool>(n, false);
        for(const auto& c : connections){
            adjl[c[0]].push_back(c[1]);
            adjl[c[1]].push_back(c[0]);
        }
        int ncc = 0;
        for(int i = 0; i<n; i++){
            if(!vstd[i]) {
                ncc++;
                cc(i);
            }
        }
        if(ncc == 1) return 0;
        return ncc-1;
    }
};
