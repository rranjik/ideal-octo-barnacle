class Solution {
public:
    struct loc {
        int r; int c; int d;
        loc(int _r, int _c, int _d):r(_r), c(_c), d(_d){}
        bool operator>(const loc& l) const {
            return d<l.d;
        }
    };
    vector<vector<vector<int>>> ca;
    int dfs(int tr, int tc, int td){
        //cout<<"at "<<tr<<", "<<tc<<" with "<<td<<endl;
        if(td>=maxMove) return 0;
        if(ca[tr][tc][td]!=-1) return ca[tr][tc][td];
        long long res = 0;
        for(const auto dd : dir){
            auto nr = tr+dd[0];
            auto nc = tc+dd[1];
            if(nr>=0&&nr<m&&nc>=0&&nc<n){
                //cout<<" pushing "<<nr<<", "<<nc<<endl;
                res+=dfs(nr, nc, td+1);
                res%=mod;
            }
            if(nr<0||nr>=m||nc<0||nc>=n){
                //if(td+1<=maxMove){
                    //cout<<"with "<<td+1<<" moves"<<endl;
                    res++;
                    res%=mod;
                //}
            }
        }
        return ca[tr][tc][td] = res;
    }
    vector<vector<int>> dir = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    int maxMove = 0;
    int m; int n;
    int mod = 1e9+7;
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        this->m = m; this->n = n;
        this->maxMove = maxMove;
        //priority_queue<loc, vector<loc>, greater<loc>> pq;
        ca = vector<vector<vector<int>>>
            (m, vector<vector<int>>(n, vector<int>(maxMove, -1)));
        return dfs(sr, sc, 0);
    }
};
