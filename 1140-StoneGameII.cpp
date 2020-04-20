struct coor{
    int i;
    int m;
    bool p;
    coor(int _i, int _m, bool _p):i(_i), m(_m), p(_p){}
    bool operator==(const coor& o)const{
        return i==o.i&&m==o.m&&p==o.p;
    }
};
namespace std{
    template<>
    struct hash<coor>{
        size_t operator()(const coor& c)const {
            return (hash<int>()(c.i)^(hash<int>()(c.m)>>1)<<1)^(hash<bool>()(c.p)<<1);
        }
    };
}
class Solution {
public:
    vector<int> p;
    int n;
    //collect x piles starting from i
    int collect(int iInclusive, int x){
        int res = 0;
        if(iInclusive<n){
            int numberOfPilesCollected = 0;
            while(x&&iInclusive+numberOfPilesCollected<n){
                res+=p[iInclusive+numberOfPilesCollected];
                x--;
                numberOfPilesCollected++;
            }
        }
        return res;
    }
    unordered_map<coor, pair<int , int>> cache;
    pair<int, int> dp(int i, int m, bool player){
        auto cr = coor(i, m, player);
        if(cache.find(cr)!=cache.end()) {
        //    if(player) {
                return cache[cr];
            //}else {
            //    auto s = cache[cr];
            //    auto pp = make_pair(s.second, s.first);
            //    return pp;
            //}
        }
        //if there are no choices 
        if(i>=n){
            cache[cr] = make_pair(0, 0);
            return make_pair(0, 0);
        }
        //else for each choice c, try c and see how it goes
        int alexGain = 0;
        int leeGain = 0;
        for(int x = 1; x<=2*m; x++){
            //if it was Alex's turn add the piles collected
            //to a 
            //int alex = a;
            //int lee = l;
            //if(p) alex+=collect(i, x);
            //else lee+=collect(i, x);
            //else add it to Lee's
            //if we collce x piles starting from i, 
            //we can only start at i+x next time 
            //around. m is set to max(x, m). 
            auto gains = dp(x+i, max(x, m), !player);
            if(player){
                if(alexGain<gains.first+collect(i, x)){
                    alexGain = gains.first + collect(i, x); 
                    leeGain = gains.second;
                }
            }else {
                if(leeGain<gains.second+collect(i, x)){
                    leeGain = gains.second + collect(i, x); 
                    alexGain = gains.first;
                }
            }
        }
        cache[cr] = make_pair(alexGain, leeGain);
        return make_pair(alexGain, leeGain);
    }
    int stoneGameII(vector<int>& piles) {
        p = piles;
        n = p.size();
        auto res = dp(0, 1, true);
        cout<<res.first<<" "<<res.second;
        return res.first;
    }
};
