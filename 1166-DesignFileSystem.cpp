class FileSystem {
public:
    unordered_map<string, int> fs;
    FileSystem() {
        
    }
    
    bool createPath(string path, int value) {
        if(path.length()==0||(path.size()==1&&path[0]=='/'))
            return false;
        if(path[0]!='/'){
            cout<<"relative paths not accepted"<<endl;
            false;
        }
        if(fs.find(path)!=fs.end()) 
            return false;
        vector<string> ppath;
        int last_pos = 1;
        int pos = 0;
        while((pos = path.find_first_of('/', last_pos))!=string::npos){
            string p = path.substr(0, pos);
            ppath.push_back(p);
            last_pos = pos+1;
        }
        for(const auto& p : ppath){
            if(fs.find(p)==fs.end()) return false;
        }
        fs[path] = value;
        return true;
    }
    
    int get(string path) {
        if(fs.find(path)==fs.end()) return -1;
        return fs[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
