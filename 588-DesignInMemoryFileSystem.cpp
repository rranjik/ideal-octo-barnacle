class FileSystem {
public:
    struct fol{
        map<string, shared_ptr<fol>> fols;
        map<string, string> files;
        fol(map<string, shared_ptr<fol>> _fols,map<string, string> _files)
            :fols(_fols), files(_files){}
        fol(){}
        bool fexists(string f) {return files.find(f)!=files.end();}
        bool dexists(string d) {return fols.find(d)!=fols.end();}
    };
    shared_ptr<fol> root;
    FileSystem() {
        map<string, shared_ptr<fol>> rfols = {
            {"/", make_shared<fol>()}
        };
        map<string, string> rfiles;
        root = make_shared<fol>(rfols, rfiles);
    }
    
    void ils(shared_ptr<fol> f, set<string>& res){
        if(!f) return;
        for(const auto& [name, contents]: f->files) res.insert(name);
        for(const auto& [name, folder]: f->fols) {
            res.insert(name);
        }
    }
    
    shared_ptr<fol> dfs(shared_ptr<fol> r, vector<string>& comps, int i){
        if(!r) return nullptr;
        if(i>comps.size()) return nullptr;
        if(i==comps.size()) return r;
        if(r->fols.find(comps[i])!=r->fols.end())
            return dfs(r->fols[comps[i]], comps, i+1);
        return nullptr;
    }
    
    vector<string> getComps(string path){
        cout<<"input to getComps = "<<path<<endl;
        istringstream ss(path);
        string t;
        vector<string> comps;
        while(getline(ss, t, '/')){
            comps.push_back(t);
        }
        for(const auto& c : comps) cout<<c<<" "; cout<<endl;
        return comps;
    }
    
    vector<string> ls(string path) {
        auto comps = getComps(path);
        auto pfile = comps.back(); comps.pop_back();
        set<string> res;
        auto dir = dfs(root, comps, 0);
        if(!dir) return {res.begin(), res.end()};
        if(dir->files.find(pfile)!=dir->files.end()) return {pfile};
        if(dir->fols.find(pfile)!=dir->fols.end()) dir = dir->fols[pfile];
        else dir = nullptr;
        if(!dir) return {res.begin(), res.end()};
        ils(dir, res);
        cout<<"ils returned "<<endl;
        return {res.begin(), res.end()};
    }
    
    shared_ptr<fol> nav(vector<string> comps){
        int i = 0;
        auto rc = root;
        while(i<comps.size()){
            auto d = comps[i];
            if(rc->fols.find(d)==rc->fols.end()){
                rc->fols.insert({d, make_shared<fol>()});
            }
            rc = rc->fols[d];
            i++;
        }
        return rc;
    }
    
    void mkdir(string path) {
        auto comps = getComps(path);
        nav(comps);
    }
    
    void addContentToFile(string filePath, string content) {
        auto comps = getComps(filePath);
        auto file = comps.back(); comps.pop_back();
        auto dir = nav(comps);
        dir->files[file]+=content;
    }
    
    string readContentFromFile(string filePath) {
        auto comps = getComps(filePath);
        auto file = comps.back(); comps.pop_back();
        auto dir = nav(comps);
        return dir->files[file];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
