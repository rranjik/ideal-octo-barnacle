class BoundedBlockingQueue {
public:
    queue<int> q;
    mutex m;
    condition_variable cv;
    int cap;
    BoundedBlockingQueue(int capacity) {
        cap = capacity;
    }
    
    void enqueue(int element) {
        unique_lock<mutex> l(m);
        cv.wait(l, [this](){return q.size()<cap;});
        q.push(element);
        cv.notify_one();
    }
    
    int dequeue() {
        unique_lock<mutex> l(m);
        cv.wait(l, [this](){return !q.empty();});
        auto ret = q.front();
        q.pop();
        cv.notify_one();
        return ret;
    }
    
    int size() {
        lock_guard<mutex> l(m);
        return q.size();
    }
};
