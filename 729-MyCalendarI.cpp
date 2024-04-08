class MyCalendar {
public:
    MyCalendar() {
        
    }
    map<int, int> e;
    bool book(int start, int end) {
        auto n = e.upper_bound(start);
        if(n!=e.end()&&(*n).second<end) return false;
        e.insert({end, start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
