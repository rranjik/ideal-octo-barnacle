namespace std{
    template<>
    struct hash<pair<int, int>>{
        size_t operator()(const pair<int, int>& p)const{
        return (hash<int>()(p.first)^0x29434830)^
        (hash<int>()(p.second)^0x2948309);
        }
    };
}
class Solution {
public:
    unordered_map<pair<int, int>, int> cache;
    int dp(int i, int d){
        auto coor = pair<int, int>(i, d);
        if(cache.find(coor)!=cache.end()) return cache[coor];
        //cout<<"endtering dp("<<i<<", "<<d<<")"<<endl;
        if(d==0&&i==-1) {
            //cout<<"dp("<<i<<", "<<d<<") returns 0"<<endl;
            cache[coor] = 0;
            return 0;
        }
        if((d>0&&i<0)||(i>=0&&d<=0)) {
            //cout<<"dp("<<i<<", "<<d<<") returns inf"<<endl;
            cache[coor] = 100000;
            return 100000;
        }
        auto cm = jd[i];
        int res = numeric_limits<int>::max();
        for(int j = i; j>=0; j--){
            cm = max(cm, jd[j]);
            int r = dp(j-1, d-1);
            //cout<<"dp("<<j-1<<", "<<d-1<<") returned "<<r<<endl;
            res = min(res, r+cm);
        }
        //cout<<"dp("<<i<<", "<<d<<") returns res = "<<res<<endl;
        cache[coor] = res;
        return res;
    }
    int diff;
    vector<int> jd;
    int minDifficulty(vector<int>& jd, int d) {
        if(jd.size()<d) return -1;
        this->jd = jd;
        return dp(jd.size()-1, d);
    }
};
