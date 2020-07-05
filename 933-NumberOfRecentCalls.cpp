class RecentCounter {
public:
    set<int> s;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        s.insert(t);
        auto l = s.lower_bound(t-3000);
        auto u = s.upper_bound(t);
        return distance(l,u);
        //int res = 0;
        //for(it = l; it!=u; it++){
        //    
        //}
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
