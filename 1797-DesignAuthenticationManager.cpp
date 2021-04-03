class AuthenticationManager {
public:
    //auth token map
    unordered_map<string, int> atm;
    int ttl{};
    int ct{};
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        atm[tokenId] = currentTime+ttl;
    }
    
    void renew(string ti, int crr) {
        ct = crr;
        if(atm.find(ti)==atm.end()) return;
        auto et = atm[ti];
        if(et>ct) atm[ti] = ct+ttl;
        else atm.erase(ti);
    }
    
    int countUnexpiredTokens(int crr) {
        ct = crr;
        int res{};
        //to remove
        unordered_set<string> tr;
        for(const auto& it : atm){
            if(it.second>crr) res++;
            else tr.insert(it.first);
        }
        for(const auto& it : tr){
            atm.erase(it);
        }
        return res;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
