class coor{
public:
    bitset<21> c;
    int sum;
    coor(bitset<21> _c, int _sum): c(_c), sum(_sum){}
    bool operator==(const coor& o)const {return c==o.c&&sum==o.sum;}
};
namespace std{
    template <>
    struct hash<coor>{
        size_t operator()(const coor& co) const {
            return hash<bitset<21>>()(co.c)>>1^(hash<int>()(co.sum));
        }
    };
}
class Solution {
public:
    int m;
    void print(bitset<21> c){
        int idx = m;
        while(idx>=0){
            cout<<idx<<"-"<<c.test(idx)<<" ";
            idx--;
        }
    }
    unordered_map<coor, bool> cache;
    bool dpdfs(bitset<21> c, int sum){
        coor co(c, sum);
        if(cache.find(co)!=cache.end()) return cache[co];
        //cout<<sum<<": ";
        //print(c);
        //cout<<endl;
        if(c.test(m)){
            //player 1's turn
            //if sum is 0 player 1 loses
            if(sum<=0) { 
                //cout<<sum<<": ";
                //print(c);
                //cout<<": ";
                //cout<<false;
                //cout<<endl;
                cache[co] = false;
                return false;
            }
            bool res = false;
            int idx = 0;
            //find all the options available
            while(!res&&idx<m) {
                //if this index is available 
                if(c.test(idx)){
                    auto ch = c;
                    ch.reset(m);
                    ch.reset(idx);
                    res |= dpdfs(ch, sum-idx-1);
                }
                idx++;
            }
            //cout<<sum<<": ";
            //print(c);
            //cout<<": ";
            //cout<<res;
            //cout<<endl;
            cache[co] = res;
            return res;
        }else {
            //player 2's turn
            if(sum<=0) { 
                //cout<<sum<<": ";
                //print(c);
                //cout<<": ";
                //cout<<true;
                //cout<<endl;
                cache[co] = true;
                return true;
            }
            bool res = true;
            int idx = 0;
            //find all the options available
            while(res&&idx<m){
                //if this index is available 
                if(c.test(idx)){
                    auto ch = c;
                    ch.set(m, true);
                    ch.reset(idx);
                    res &= dpdfs(ch, sum-idx-1);
                }
                idx++;
            }
            //cout<<sum<<": ";
            //print(c);
            //cout<<": ";
            //cout<<res;
            //cout<<endl;
            cache[co] = res;
            return res;
        }
    }
    bool canIWin(const int maxChoosableInteger, int desiredTotal) {
        if(((maxChoosableInteger*(maxChoosableInteger+1))/2)<desiredTotal) return false;
        if(!desiredTotal) return true;
        m = maxChoosableInteger;
        bitset<21> c;
        int idx = 0;
        while(idx<c.size()){
            c.set(idx);
            idx++;
        }
        return dpdfs(c, desiredTotal);
    }
};
