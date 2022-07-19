class MaxStack {
public:
    /** initialize your data structure here. */
    using pii = pair<int, int>;
    stack<pii> stk;
    MaxStack() {
        
    }
    
    void push(int x) {
        if(stk.empty()) stk.push(make_pair(x, x));
        else{
            if(stk.top().first>=x){
                stk.push(make_pair(stk.top().first, x));
            }else{
                stk.push(make_pair(x, x));
            }
        }
    }
    
    int pop() {
        auto ret = stk.top().second;
        stk.pop();
        return ret;
    }
    
    int top() {
        return stk.top().second;
    }
    
    int peekMax() {
        return stk.top().first;
    }
    
    int popMax() {
        auto m = stk.top().first;
        stack<pair<int, int>> buff;
        while(stk.top().second<m){
            buff.push(stk.top());
            stk.pop();
        }
        stk.pop();
        while(!buff.empty()){
            if(!stk.empty()&&stk.top().first>=buff.top().second){
                stk.push(make_pair(stk.top().first, buff.top().second));
            }else{
                stk.push(make_pair(buff.top().second, buff.top().second));
            }
            buff.pop();
        }
        return m;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
