class HitCounter {
public:
    /** Initialize your data structure here. */
    map<int, int> m;
    HitCounter() {
        
    }
    
    void refresh(int t){
        int from = 0;
        int to = t-300;
        m.erase(m.begin(), m.upper_bound(to));
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int t) {
        if(m.find(t)!=m.end()){
            m[t]++;
        }else{
            m[t] = 1;
        }
        refresh(t);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int t) {
        auto l = m.lower_bound(t-300+1);
        auto h = m.upper_bound(t);
        int res = 0;
        for(auto it = l; it!=h; it++){
            cout<<it->first<<" "<<it->second<<endl;
            res+=it->second;
        }
        //refresh(t);
        return res;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
