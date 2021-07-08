class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    map<int, int> t;
    int book(int s, int e) {
        //like an range sum
        //s denotes a +1 to pick along the way
        t[s]++;
        //e denotes a -1 to drop along the way
        t[e]--;
        int res = 0;
        int concur = 0;
        //run the entire time line picking up and dropping 
        //as nescessary
        
        // [-------------)
        //      [--------)
        //               [---)
        // 1    2        1   0 
        for(const auto& v : t){
            res = max(res, concur+=v.second);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
