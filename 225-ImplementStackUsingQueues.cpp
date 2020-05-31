class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    void swapy(){
        if(q1.empty()){
            return;
        }else{
            auto e = q1.front();
            q1.pop();
            swapy();
            q2.push(e);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(!q2.empty()){
            auto e = q2.front();
            q2.pop();
            return e;
        }else{
            swapy();
            auto e = q2.front();
            q2.pop();
            return e;
        }
    }
    
    /** Get the top element. */
    int top() {
        if(!q1.empty())
            return q1.back();
        else return q2.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        cout<<q1.size()<<" "<<q2.size()<<endl;
        return q1.empty()&&q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
