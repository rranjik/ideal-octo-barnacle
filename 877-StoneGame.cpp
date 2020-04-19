class coor{
public:
    int j;
    int i;
    int a;
    int l;
    coor(int _i, int _j, int _a, int _l):i(_i), j(_j), a(_a), l(_l){}
    bool operator==(const coor& o) const {
        return i==o.i&&j==o.j&&a==o.a&&l==o.l;
    }
};
namespace std{
    template <>
    struct hash<coor>{
       size_t operator()(const coor& c)const{
           return (hash<int>()(c.i)^0x503204891>>1)^
           (hash<int>()(c.j)^0x204839233>>1)^
           (hash<int>()(c.a)^0x393853807>>1)^
           (hash<int>()(c.l)^0x082043921>>1);
       }  
    };
}
class Solution {
public:
    vector<int> p;
    unordered_map<coor, bool> c;
    bool dp(int i, int j, int a, int l){
        auto cr = coor(i,j,a,l);
        if(c.find(cr)!=c.end()) return c[cr];
        if(j<i){
            if(a>l){
                c[cr] = true;
                return true;
            }
            else {
                c[cr] = false;
                return false;
            }
        }
        if(j==i){
            if(a+p[i]>l) {
                c[cr] = true;
                return true;
            }
            else {
                c[cr] = false;
                return false;
            }
        }else{
            if((j-i%2)){
                auto res = false;
                res |= dp(i+1, j, a+p[i], l);
                res |= dp(i, j-1, a+p[j], l);
                c[cr] = res;
                return res;
            }else {
                auto res = true;
                res &= dp(i+1, j, a, l+p[i]);
                res &= dp(i, j-1, a, l+p[j]);
                c[cr] = res;
                return res;
            }
        }
    }
    bool stoneGame(vector<int>& piles) {
        p = piles;
        return dp(0, piles.size()-1, 0, 0);
    }
};
