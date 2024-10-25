class FrontMiddleBackQueue {
public:
    deque<int> a, b;
    void a2b(){
        if(a.size()<=b.size()) return;
        //else we know that
        //a.size()>b.size()
        //or a has become too big
        b.push_front(a.back());
        a.pop_back();
    }
    void b2a(){
        if(b.size() <= a.size()+1) return;
        // else we know that 
        //b.size() > a.size()+1 (opposite)
        //or b.size()-1 > a.size() 
        //or a has become too small
        a.push_back(b.front());
        b.pop_front();
    }
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        a.push_front(val);
        if(a.size()>b.size())
            a2b();
    }
    
    void pushMiddle(int val) {
        a.push_back(val);
        a2b();
    }
    
    void pushBack(int val) {
        b.push_back(val);
        b2a();
    }
    
    int popFront() {
        if(a.empty()&&b.empty()) return -1;
        int res = -1;
        if(!a.empty()) {
            res = a.front();
            a.pop_front();
            b2a();
        }else{
            res = b.front();
            b.pop_front();
        }
        return res;
    }
    
    int popMiddle() {
        if(a.empty()&&b.empty()) return -1;
        int res = -1;
        if(a.size()==b.size()){
            res = a.back();
            a.pop_back();
            //b2a not required as 
            //a has just become one
            //less than b
        }else{//a was already one less than b
            //now they become equal, so no 
            //adjustment required
            res = b.front();
            b.pop_front();
        }
        return res;
    }
    
    int popBack() {
        if(a.empty()&&b.empty()) return -1;
        auto sizeeq = a.size()==b.size();
        auto res = b.back();
        b.pop_back();
        if(sizeeq) a2b();
        return res;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
