class config{
public:
    int kl;
    int sl;
    //int bl;
    config(int k, int s/*, int b*/):kl(k), sl(s)/*, bl(b)*/{}
    inline bool operator==(const config& c) const {
        return kl==c.kl/*&&bl==c.bl*/&&sl==c.sl;
    }
};
namespace std{
    template<>
    struct hash<pair<int, int>> {
        inline size_t operator()(const pair<int, int>& c) const {
            return ((hash<int>()(c.first)))^
            (hash<int>()(c.second));
            /*(hash<int>()(c.bl)^0xA84C4837);*/
        }
    };
}
class Solution {
public:
    unordered_map<pair<int, int>, int> c;
    int dp(int kl, int sl){
        auto co = make_pair(kl, sl);
        if(c.find(co)!=c.end()) return c[co];
        if(kl<=0){
            c[co] = sl;
            //cout<<"returning "<<sl<<endl;
            return sl;
        }
        int copy = numeric_limits<int>::min();
        for(int i = 0; (sl>0)&&((kl-(i+3))>=0)&&i<kl-2; i++){
            //cout<<"kl = "<<kl<<"; sl = "<<sl<<
            //"; i = "<<i<<"; left = "<<(kl-(i+3))<<
            //"; mult by "<<(i+2)<<endl;
            copy = max(copy , dp(kl-(i+3), sl*(i+2)));
        }
        int typeA = dp(kl-1, sl+1);
        int res = max(typeA, copy);
        c[co] = res;
        return res;
    }
    int maxA(int N) {
        return dp(N, 0);
    }
};
