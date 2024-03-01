class MyHashMap {
public:
    int mod = 499;
    vector<list<pair<int, int>>> v;
    MyHashMap() {
        v = vector<list<pair<int, int>>> (mod+1);
    }
    
    void put(int key, int value) {
        auto ins_key = key%mod;
        if(v[ins_key].size()==0){
            auto kvp = pair<int, int>({key, value});
            v[ins_key].push_back(kvp);
            return;
        }
        auto head = v[ins_key].begin();
        while(head!=v[ins_key].end()){
            if(head->first==key){
                head->second = value;
                return;
            }
            head = next(head);
        }
        v[ins_key].push_back({key, value});
    }
    
    int get(int key) {
        auto ins_key = key%mod;
        if(v[ins_key].size()==0){
            return -1;
        }
        auto head = v[ins_key].begin();
        while(head!=v[ins_key].end()){
            if(head->first==key){
                return head->second;
            }
            head = next(head);
        }
        return -1;
    }
    
    void remove(int key) {
        auto ins_key = key%mod;
        if(v[ins_key].size()==0){
            return;
        }
        auto head = v[ins_key].begin();
        while(head!=v[ins_key].end()){
            if(head->first==key){
                auto nextn = next(head);
                v[ins_key].erase(head);
                return;
            }
            head = next(head);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
