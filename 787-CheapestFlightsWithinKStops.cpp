class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, 
                          int dst, int K) {
        vector<int> c(n, 1e9);
        c[src] = 0;
        for(int i = 0; i<K+1; i++){
            vector<int> C(c);
            for(const auto f : flights)
                C[f[1]] = min(C[f[1]], c[f[0]]+f[2]);
            c = C;
        }
        return c[dst]==1e9?-1:c[dst];
    }
};
