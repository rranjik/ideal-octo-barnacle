namespace std{
    template <>
    struct hash<pair<int, int>>{
       size_t operator()(const pair<int, int>& p) const {
           return hash<int>()(p.first)^(hash<int>()(p.second)>>1);
       } 
    };
}
class Solution {
public:
    vector<int> v;
    int maxi(int i, int j){
        if(j>=i&&j<v.size()){
            int res = v[i];
            for(int k = i; k<=j; k++){
                res = max(res, v[k]);
            }
            return res;
        }else return 1;
    }
    unordered_map<pair<int, int>, int> c;
    int dp(int i, int j){
        auto p = make_pair(i, j);
        if(c.find(p)!=c.end()) return c[p];
        if(j<i||j>=v.size()){
            cout<<"i = "<<i<<"; j = "<<j<<": 0"<<endl;
            c[p] = 0;
            return 0;
        }
        if(j==i) {
            cout<<"i = "<<i<<"; j = "<<j<<": "<<0<<endl;
            c[p] = 0;
            return 0;
        }
        int res = numeric_limits<int>::max();
        for(int k = i; k<j; k++){
            res = min(res, maxi(i, k)*maxi(k+1, j)+dp(i, k) + dp(k+1, j));
        }
        cout<<"i = "<<i<<"; j = "<<j<<": "<<res<<endl;
        c[p] = res;
        return res;
    }
    int mctFromLeafValues(vector<int>& arr) {
        v = arr;
        return dp(0, v.size()-1);
    }
};
