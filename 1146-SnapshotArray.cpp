//versioned value
class vv{
public:
    int s{};
    int v{};
    vv(int _s, int _v):s(_s), v(_v){};
    bool operator<(const vv& i)const {
        return s<i.s;
    }
};
class SnapshotArray {
public:
    vector<vector<vv>> v;
    int snp = 0;
    SnapshotArray(int length) {
        v = vector<vector<vv>>(length);
    }
    
    void set(int index, int val) {
        if(v[index].size()&&v[index].back().s == snp){
            v[index].back().v = val;
        }else{
            v[index].push_back(vv(snp, val));
        }
    }
    
    int snap() {
        snp++;
        return snp-1;
    }
    
    int get(int index, int snap_id) {
        auto it = lower_bound(begin(v[index]), end(v[index]), vv(snap_id, 0));
        if(it==v[index].end()) {
            if(!v[index].size()) return 0;
            return v[index].back().v;
        }
        if((*it).s==snap_id){
            return (*it).v;
        }
        if(it==v[index].begin()) return 0;
        it = prev(it);
        return (*it).v;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
