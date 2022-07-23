class FirstUnique {
public:
    unordered_map<int, list<int>::iterator> m;
    unordered_set<int> seen;
    list<int> l;
    FirstUnique(vector<int>& nums) {
        for(const auto& n : nums) add(n);
    }
    
    int showFirstUnique() {
        if(l.size()){
            return *(l.begin());
        }else return -1;
    }
    
    void add(int value) {
        if(m.find(value)==m.end()){
            l.push_back(value);
            m[value] = prev(l.end());
        }else{
            if(m[value]!=l.end()){
                l.erase(m[value]);
                m[value] = l.end();
            }
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
