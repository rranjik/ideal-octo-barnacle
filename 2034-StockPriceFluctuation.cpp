class StockPrice {
public:
    int latest = 0;
    int latestp = 0;
    unordered_map<int, int> p;
    map<int, int> h;
    StockPrice() {
        
    }
    
    void update(int t, int pr) {
        if(p.find(t)!=p.end()){
            h[p[t]]--;
            if(h[p[t]]==0){
                h.erase(p[t]);
            }
        }
        p[t] = pr;
        h[pr]++;
        if(t>=latest){
            latest = t;
            latestp = pr;
        }
    }
    
    int current() {
        return latestp;
    }
    
    int maximum() {
        return (*h.rbegin()).first;
    }
    
    int minimum() {
        return (*h.begin()).first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
