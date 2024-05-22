class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> g;
        int r = grid.size();
        if(!r) return 0;
        int c = grid[0].size();
        if(r*c==1) return 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                g.push_back(grid[i][j]);
            }
        }
        int n = g.size();
        sort(g.begin(), g.end());
        for(int i = 0; i<n-1; i++){
            if((g[i+1]-g[i])%x)
                return -1;
        }
        vector<long long> fs(n);
        vector<long long> bs(n);
        for(int i = 1; i<n; i++){
            fs[i] = g[i-1]+fs[i-1];
        }
        for(int i = n-2; i>=0; i--){
            bs[i] = g[i+1]+bs[i+1];
        }
        //for(const auto& v : g) //cout<<v<<" "; //cout<<endl;
        //for(const auto& v : fs) //cout<<v<<" "; //cout<<endl;
        //for(const auto& v : bs) //cout<<v<<" "; //cout<<endl;
        long long res = numeric_limits<long long>::max();
        auto found = false;
        for(int i = 0; i<g.size(); i++){
            auto h = g[i];
            long long sbefore = (i)*h;
            long long leftbefore = sbefore - fs[i];
            //cout<<"i = "<<i<<" sbefore = "<<sbefore<<" leftbefore = "<<leftbefore<<endl;
            if(leftbefore%x) continue;
            long long safter = (n-i-1)*h;
            long long moreafter = bs[i] - safter;
            //cout<<"i = "<<i<<" safter = "<<safter<<" moreafter = "<<moreafter<<endl;
            if(moreafter%x) continue;
            found = true;
            res = min(res, (leftbefore/x) + (moreafter/x));
        }
        if(found)
            return res;
        return -1;
    }
};
