class LFUCache {
public:
    int cap;
    int size; 
    int minFreq;
    //keys are unique
    unordered_map<int, pair<int, int>> m;
    //key to where is it ?
    unordered_map<int, list<int>::iterator> miter;
    //kinda inv freq, freq -> all keys with frequency freq
    unordered_map<int, list<int>> fm;
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        fm[m[key].second].erase(miter[key]);
        m[key].second++;
        fm[m[key].second].push_back(key);
        miter[key]=prev(fm[m[key].second].end());
        if(!fm[minFreq].size()) minFreq++;
        return m[key].first;
    }
    
    void put(int key, int value) {
        if(cap<=0) return;
        
        int val = get(key);
        if(val!=-1) {
            m[key].first = value;
            return;
        }
        if(size>=cap){
            m.erase(fm[minFreq].front());
            miter.erase(fm[minFreq].front());
            fm[minFreq].pop_front();
            size--;
        }
        
        m[key] = {value, 1};
        fm[1].push_back(key);
        miter[key] = prev(fm[1].end());
        minFreq = 1;
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
/*
        m[key]={value, 1};
        fm[1].push_back(key);
        mIter[key]=--fm[1].end();
        minFreq=1;
        size++;
    }
};
*/
