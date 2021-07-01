class DinnerPlates {
public:
    map<int, stack<int>> m;
    set<int> available;
    int cap{};
    DinnerPlates(int capacity) {
        cap = capacity;
    }
    
    void push(int val) {
        if(available.empty()){
            available.insert(m.size());
        }
        m[*available.begin()].push(val);
        if(m[*available.begin()].size()==cap){
            available.erase(available.begin());
        }
    }
    
    int pop() {
        if(!m.size()) return -1;
        return popAtStack((*m.rbegin()).first);
    }
    
    int popAtStack(int index) {
        if(m.find(index)==m.end()) return -1;
        auto ret = m[index].top();
        m[index].pop();
        //set uniqueness takes care of duplicates
        available.insert(index);
        //why remove ?!
        if(!m[index].size()) m.erase(m.find(index));
        return ret;
    }
};

/*
    int c;
    map<int, vector<int>> m;
    set<int> available;

    DinnerPlates(int capacity) {
        c = capacity;
    }

    void push(int val) {
        if (available.empty())
            available.insert(m.size());
        m[*available.begin()].push_back(val);
        if (m[*available.begin()].size() == c)
            available.erase(available.begin());
    }

    int pop() {
        if (m.empty()) return -1;
        return popAtStack(m.rbegin()->first);
    }

    int popAtStack(int index) {
        if (!m.count(index) || m[index].empty())
            return -1;
        int val = m[index].back();
        m[index].pop_back();
        available.insert(index);
        if (m[index].empty())
            m.erase(index);
        return val;
    }
*/

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
