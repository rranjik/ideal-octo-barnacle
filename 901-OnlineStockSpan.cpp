class StockSpanner {
public:
    stack<pair<int, int>> stk;
    StockSpanner() {
        
    }
    int d{};
    int next(int price) {
        d++;
        if(!stk.empty()){
            int res{};
            while(!stk.empty()&&stk.top().first<=price) {
                stk.pop();
            }
            if(stk.empty()) {
                res = d;
            }else{
                res = d-stk.top().second;
            }
            cout<<"pushing {"<<price<<", "<<d<<"}"<<endl;
            stk.push({price, d});
            return res;
        }else{
            stk.push({price, d});
            return d;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
