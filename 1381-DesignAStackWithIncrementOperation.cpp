class CustomStack {
public:
    vector<int> stk;
    int currsize = 0;
    int maxsize = 0;
    CustomStack(int maxSize) {
        maxsize = maxSize;
    }
    
    void push(int x) {
        if(currsize<maxsize){
            stk.push_back(x);
            currsize++;
        }
    }
    
    int pop() {
        if(currsize>=1){
            auto ret = stk.back();
            stk.pop_back();
            currsize--;
            return ret;
        }
        return -1;
        
    }
    
    void increment(int k, int val) {
        for(int i = 0; i<min(currsize, k); i++){
            stk[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
