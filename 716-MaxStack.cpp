class MaxStack {
public:
    /** initialize your data structure here. */
    using lit = list<int>::iterator;
    list<int> dll;
    map<int, vector<lit>> m;
    MaxStack() {
        
    }
    
    void push(int x) {
        dll.insert(dll.begin(), x);
        m[x].push_back(dll.begin());
    }
    
    int pop() {
        auto it = dll.begin();
        auto ret = *it;
        m[ret].pop_back();
        if(!m[ret].size()) m.erase(m.find(ret));
        dll.erase(it);
        return ret;
    }
    
    int top() {
        return *dll.begin();
    }
    
    int peekMax() {
        return m.rbegin()->first;
    }
    
    int popMax() {
        auto it = m.rbegin()->second.back();
        auto ret = *it;
        m[ret].pop_back();
        if(!m[ret].size()) m.erase(m.find(ret));
        dll.erase(it);
        return ret;
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
