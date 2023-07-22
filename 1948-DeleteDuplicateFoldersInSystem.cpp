class Solution {
public:
    struct fs{
        //dir name
        string dn;
        size_t h;
        int cnt = 0;
        unordered_map<string, fs*> c;
        fs(){
            dn = "-";
        }
        fs(string _dn){
            dn = _dn;
        }
        void insert(fs* f, const vector<string>& p, int i){
            //for(int i = 0; i<p.size(); i++){
            //    if(f->c.find(p[i])==f->c.end()) {
            //        f->c[p[i]] = new fs(p[i]);
            //    }
            //    f = f->c[p[i]];
            //}
            if(i==p.size()) return;
            const auto& name = p[i];
            cnt++;
            if(c.find(name)!=c.end()) {
                c[name]->insert(f, p, i+1);
                return;
            }
            c[name] = new fs(name);
            c[name]->insert(f, p, i+1);
        }
    };
    unordered_map<size_t, int> reps;
    unordered_map<size_t, vector<fs*>> htof;
    unordered_set<fs*> todel;
    size_t traverse(fs* f){
        if(!f) return 0;
        //cout<<"traverse at "<<f->dn<<" #children = "<<f->c.size()<<endl;
        size_t hh = 0;
        if(!f->c.size()){
            auto reth = hash<string>()(f->dn)&0xef14c29d;
            return reth;
        }
        for(const auto& it : f->c){
            hh = hash<size_t>()(hh^hash<size_t>()(traverse(it.second))>>2);
        }
        f->h = hh;
        reps[hh]++;
        htof[hh].push_back(f);
        auto res = hash<size_t>()(hash<string>()(f->dn)|f->h)^0x29cf2e2a;
        //cout<<"dn = "<<f->dn<<" hash = "<<hh<<endl;
        return res;
    }
    void dedup(){
        for(const auto& h : reps){
            if(h.second>1) {
                for(const auto& sd : htof[h.first]){
                    //cout<<"todel "<<sd->dn<<endl;
                    todel.insert(sd);
                }
            }
        }
    }
    void collect(fs* f, fs* p){
        if(!f) return;
        if(todel.find(f)!=todel.end()){
            p->cnt--;
            //cout<<"deleted "<<f->dn<<" parent = "<<p->dn<<endl;
            return;
        }
        for(const auto& ch : f->c){
            collect(ch.second, f);
        }
    }
    fs root;
    void build(fs* f, vector<string>& p, vector<vector<string>>& res){
        if(!f) {
            return;
        }
        //cout<<"build at "<<f->dn<<" #children = "<<f->c.size()<<endl;
        if(!f->c.size()){
            res.push_back(p);
            return;
        }
        if(p.size())
            res.push_back(p);
        for(const auto& ch : f->c){
            if(todel.find(ch.second)==todel.end()){
                p.push_back(ch.second->dn);
                build(ch.second, p, res);
                p.pop_back();
            }
        }
    }
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        //sort(paths.begin(), paths.end(), [](const vector<string>& a, const vector<string>& b){
        //    return a.size()<b.size();
        //});
        for(int i = 0; i<paths.size(); i++){
            root.insert(&root, paths[i], 0);
        }
        traverse(&root);
        dedup();
        //collect(&root, nullptr);
        vector<vector<string>> res;
        vector<string> p;
        build(&root, p, res);
        return res;
    }
};
