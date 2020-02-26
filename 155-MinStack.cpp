class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int x) {
        if(st.empty()){
            st.push(pair<int, int>(x,x));
        }
        else{
            auto cm = st.top().second;
            if(x<cm){
                st.push(pair<int, int>(x,x));
            }
            else {
                st.push(pair<int, int>(x,cm));
            }
        }
    }
    
    void pop() {
        return st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
