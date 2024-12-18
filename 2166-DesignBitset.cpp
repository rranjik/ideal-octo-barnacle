class Bitset {
public:
    string s;
    int cnt = 0;
    string fs;
    int fcnt = 0;
    Bitset(int size) {
        s = string(size, '0');
        fs = string(size, '1');
        fcnt = size;
    }
    
    void fix(int idx) {
        if(s[idx]=='0') {
            cnt++;
            fcnt--;
            s[idx] = '1';
            fs[idx] = '0';
        }
    }
    
    
    void unfix(int idx) {
        if(s[idx]=='1') {
            cnt--;
            fcnt++;
            s[idx] = '0';
            fs[idx] = '1';
        }
    }
    
    void flip() {
        swap(fs, s);
        swap(cnt, fcnt);
    }
    
    bool all() {
        return cnt==s.size();
    }
    
    bool one() {
        return cnt>=1;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
