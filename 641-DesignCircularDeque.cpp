class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    class Node{
    public:
        int val;
        shared_ptr<Node> next{nullptr};
        shared_ptr<Node> prev{nullptr};
        explicit Node(int v): val(v){}
    };
    int cap{0};
    int size{0};
    shared_ptr<Node> head{nullptr};
    shared_ptr<Node> tail{nullptr};
    MyCircularDeque(int k) {
        cap = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(size==cap) return false;
        size++;
        auto nn = make_shared<Node>(value);
        nn->next = head;
        if(head)
            head->prev = nn;
        head = nn;
        if(!tail) tail = head;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(size==cap) return false;
        size++;
        auto nn = make_shared<Node>(value);
        nn->prev = tail;
        if(tail)
            tail->next = nn;
        tail = nn;
        if(!head) head = tail;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(size==0) return false;
        auto nextE  = head->next;
        head->next = nullptr;
        if(nextE) nextE->prev = nullptr;
        if(head==tail){
            head = nextE;
            tail = nextE;
        }
        head = nextE;
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(size==0) return false;
        auto prevE = tail->prev;
        tail->prev = nullptr;
        if(prevE) prevE->next = nullptr;
        if(head==tail){
            head = prevE;
            tail = prevE;
        }
        tail = prevE;
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(size==0) return -1;
        return head->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(size==0) return -1;
        return tail->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size==0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
       return size==cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
