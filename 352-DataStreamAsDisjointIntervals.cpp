class SummaryRanges {
public:
    /** Initialize your data structure here. */
    vector<int> n;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto it = lower_bound(begin(n), end(n), val);
        if(it==end(n)||*it>val)
            n.insert(upper_bound(begin(n), end(n), val), val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for(int i = 0; i<n.size(); i++){
            if(!i) res.push_back({n[i], n[i]});
            else {
                if(res.back()[1]+1 == n[i]) res.back()[1] = n[i];
                else res.push_back({n[i], n[i]});
            }
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
