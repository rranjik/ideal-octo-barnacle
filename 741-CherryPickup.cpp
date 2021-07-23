struct point{
    int r1; int c1; int r2;
    point(int _r1, int _c1, int _r2):r1(_r1), c1(_c1), r2(_r2){}
    bool operator==(const point& p)const{return r1==p.r1&&c1==p.c1&&r2==p.r2;}
};
namespace std{
    template<>
    struct hash<point>{
        size_t operator()(const point& p)const {
            return (hash<int>()(p.r1)^0x68493729)^
            (hash<int>()(p.c1)^0x294839483)^
            (hash<int>()(p.r1)^0x593759248);
        }
    };
}
class Solution {
public:
    int dp(int r1, int c1, int r2){
        int c2 = (r1+c1-r2);
        if(r1>=n||c1>=n||r2>=n||c2>=n||g[r1][c1]==-1||g[r2][c2]==-1) return -1e9;
        if(r1==n-1&&c1==n-1) return g[r1][c1];
        auto res = g[r1][c1];
        if(c[r1][c1][r2]!=-1) return c[r1][c1][r2];
        if(r1!=r2&&c1!=c2) res+=g[r2][c2];
        res+=max({dp(r1+1, c1, r2+1), dp(r1, c1+1, r2+1), 
                 dp(r1+1, c1, r2), dp(r1, c1+1, r2)});
        c[r1][c1][r2] = res;
        return res;
    }
    vector<vector<int>> g;
    vector<vector<vector<int>>> c;
    int n = 0;
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        if(!n) return 0;
        g = grid;
        c = vector<vector<vector<int>>>(n, 
           vector<vector<int>>(n, vector<int>(n, -1)));
        auto res = dp(0, 0, 0);
        if(res<0) return 0;
        return res;
    }
};
