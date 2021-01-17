class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    unordered_set<int> avail;
    unordered_set<int> used;
    int mn;
    PhoneDirectory(int maxNumbers) {
        mn = maxNumbers;
        for(int i = 0; i<maxNumbers; i++){
            avail.insert(i);
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(avail.size()){
            auto res = *avail.begin();
            avail.erase(avail.begin());
            used.insert(res);
            return res;
        }else return -1;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if(avail.find(number)==avail.end()) return false;
        else return true;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        auto n = used.find(number);
        if(n==used.end()) return;
        auto nn = *n;
        used.erase(n);
        avail.insert(nn);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
