class MapSum {
public:
    /** Initialize your data structure here. */
    map<string, int> m;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        auto l = m.lower_bound(prefix);
        if(l!=m.end()){
            int res = 0;
            for(auto it = l; it!=m.end()&&(!((*it).first.find(prefix, 0))); it++){
                res+=(*it).second;
            }
            return res;
        }
        return 0;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
