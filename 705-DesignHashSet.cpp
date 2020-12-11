class MyHashSet {
public:
    vector<bool> n;
    /** Initialize your data structure here. */
    MyHashSet() {
        n = vector<bool>(1000001);
    }
    
    void add(int key) {
        n[key] = true;
    }
    
    void remove(int key) {
        n[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return n[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
