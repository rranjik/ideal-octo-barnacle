class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> n;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        n.insert(upper_bound(begin(n), end(n), num), num);
    }
    
    double findMedian() {
        if(!n.size()) return 0;
        if(n.size()%2){
            return n[n.size()/2];
        }
        auto m = n.size()/2;  
        auto l = n[m];
        auto r = n[m-1];
        return (l+r)/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
