class NumberContainers {
public:
    unordered_map<int, set<int>> p;
    unordered_map<int, int> m;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(m.find(index)!=m.end()){
            auto oldn = m[index];
            p[oldn].erase(index);
            if(p[oldn].empty()) {
                p.erase(oldn);
            }
        }
        m[index] = number;
        p[number].insert(index);
    }
    
    int find(int number) {
        if(p.find(number)==p.end()) return -1;
        return *p[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
