class RandomizedSet {
public:
    /** Initialize your data structure here. */
    set<int> s;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.find(val)==s.end()){
            s.insert(val);
            return true;
        }else return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(s.find(val)==s.end()){
            return false;
        }else {
            s.erase(s.find(val));
            return true;
        };
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0,s.size()-1); // distribution in range [0, s.size()-1]

        //std::cout << dist6(rng) << std::endl;
        int probe = dist(rng);
        auto it = s.begin();
        advance(it,probe);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
