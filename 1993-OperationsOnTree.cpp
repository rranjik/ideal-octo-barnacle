class LockingTree {
public:
    vector<int> anc;
    vector<bool> lck;
    int n;
    unordered_map<int, vector<int>> dec;
    LockingTree(vector<int>& parent) {
        n = parent.size();
        anc = parent;
        lck = vector<bool>(n);
        for(int i = 0; i<n; i++){
            int p = parent[i];
            while(p!=-1){
                dec[p].push_back(i);
                p = parent[p];
            }
        }
        usr = vector<int>(n, -1);
        //for(const auto& [c, d] : dec){
        //    cout<<c<<" :";
        //    for(const auto& v : d){
        //        cout<<v<<" ";
        //    }
        //    cout<<endl;
        //}
    }
    
    bool anyAncLocked(int c){
        if(c==-1) return false;
        bool res = false;
        if(lck[c]) return true;
        return res|anyAncLocked(anc[c]);
    }
    
    bool anyDecLocked(int c){
        for(const auto& d : dec[c]){
            if(lck[d]) return true;
        }
        return false;
    }
    
    vector<int> usr;
    
    bool lock(int num, int user) {
        if(lck[num]) return false;
        lck[num] = true;
        usr[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(!lck[num]) return false;
        if(usr[num] != user) return false;
        lck[num] = false;
        usr[num] = -1;
        return true;
    }
    
    bool upgrade(int num, int user) {
        if(lck[num]) return false;
        if(!anyDecLocked(num)) return false;
        if(anyAncLocked(num)) return false;
        lck[num] = true;
        usr[num] = user;
        for(const auto& d : dec[num]){
            lck[d] = false;
            usr[d] = -1;
        }
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
