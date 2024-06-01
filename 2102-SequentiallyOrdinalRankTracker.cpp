class SORTracker {
public:
    int i = 0;
    struct sor{
        string s;
        int p;
        sor(string _s, int _p){
            s = _s; p = _p;
        }
        bool operator>(const sor& l) const {
            if(p!=l.p) return p>l.p;
            return s<l.s;
        }
        bool operator<(const sor& l) const {
            if(p!=l.p) return p<l.p;
            return s>l.s;
        }
    };
    priority_queue<sor, vector<sor>, greater<sor>> spq;
    priority_queue<sor> gpq;
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        spq.push(sor(name, score));
        gpq.push(spq.top());
        spq.pop();
    }
    
    string get() {
        auto p = gpq.top();
        spq.push(p);
        gpq.pop();
        i++;
        return p.s;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
