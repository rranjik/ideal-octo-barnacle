class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    int head{};
    int tail{};
    vector<int> q;
    int k;
    MyCircularQueue(int k) {
        this->k = k+1;
        q = vector<int>(k+1);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if((tail+1)%k==head) return false;
        q[tail] = value;
        tail = (tail+1)%k;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(head==tail) return false;
        head = (head+1)%k;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(head==tail) return -1;
        return q[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(head==tail) return -1;
        return q[(tail-1+k)%k];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head==tail;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (tail+1)%k==head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
