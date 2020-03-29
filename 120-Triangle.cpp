class coor{
public:
    int i;
    int l;
    coor(int _i, int _l){i=_i; l=_l;}
    bool operator==(const coor& other)const{return i==other.i&&l==other.l;}
};
namespace std{
    template<>
    struct hash<coor>{
        size_t operator()(const coor& c)const {
            return (hash<int>()(c.i)^(hash<int>()(c.l)<<1)>>1);
        }
    };
}
class Solution {
public:
    vector<vector<int>> t;
    int n;
    unordered_map<coor, int> c;
    int dp(const int i, const int l){
        coor cr(i,l);
        if(c.find(cr)!=c.end())return c[cr];
        if(l==n-1) {c[cr] = t[l][i];
        //cout<<"i = "<<i<<"; l = "<<l<<"; res = "<<rs<<endl;
                  return c[cr];}
        int res;
        res = min(dp(i+1, l+1), dp(i,l+1))+t[l][i];
        c[cr] = res;
        //cout<<"i = "<<i<<"; l = "<<l<<"; rs = "<<rs<<"; res = "<<res<<endl;
        return res;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        t = triangle;
        //cout<<"t[1][1] = "<<t[1][1]<<endl;
        n = t.size();
        return dp(0, 0);
    }
};
