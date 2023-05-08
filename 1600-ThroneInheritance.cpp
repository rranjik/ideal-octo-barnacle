class ThroneInheritance {
public:
    unordered_map<string, vector<string>> tree;
    unordered_map<string, bool> alive;
    string root;
    ThroneInheritance(string kingName) {
        root = kingName;
        alive[kingName] = true;
    }
    
    void birth(string parentName, string childName) {
        tree[parentName].push_back(childName);
        alive[childName] = true;
    }
    
    void death(string name) {
        alive[name] = false;
    }
    
    void dfs(string c, vector<string>& res){
        if(alive[c]){
            res.push_back(c);
        }
        for(const auto& s : tree[c]){
            dfs(s, res);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        dfs(root, res);
        return res;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
