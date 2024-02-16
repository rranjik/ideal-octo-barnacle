class LRUCache {
public:
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        auto posit = m[key];
        l.splice(l.begin(), l, posit);
        m[key] = l.begin();
        return m[key]->second;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            auto posit = m[key];
            l.splice(l.begin(), l, posit);
            m[key]->second = value;
            return;
        }
        l.push_front({key, value});
        m[key] = l.begin();
        if(m.size()>cap){
            auto torem = l.rbegin();
            auto keytorem = torem->first;
            l.erase(m[torem->first]);
            m.erase(m.find(keytorem));
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 *
