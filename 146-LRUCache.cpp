class LRUCache {
public:
    int c;
    //key and pointer to key-value pair in list
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;
    LRUCache(int capacity) {
        this->c = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it!=m.end()) {
            //if found take that element (pointer obtained by 
            //hash lookup), insert at the beginning. w/ l.splice
            //list.splice(pos, list, pointer)
            //transfer pointer from list to *this at pos
            l.splice(l.begin(), l, it->second);
            return m[key]->second;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        //if found, remove the element pointer to by the 
        //pointer (obtained by hash loopkup)
        if(it!=m.end()) l.erase(m[key]);
        //this happens regarless of the item being found
        //put the thing in the front of the list
        l.push_front(pair<int, int>(key, value));
        //rewrite the pointer in hashtable
        m[key] = l.begin();
        if(m.size()>c){
            //if we hit cap by this insert
            //get they key of the last elem in list
            auto k = l.rbegin()->first;
            //remove last
            l.pop_back();
            //evict by key
            m.erase(k);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
