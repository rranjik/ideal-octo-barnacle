class Robot {
public:
    struct p{
        int r;
        int c;
        string d;
        p(int _r, int _c, string _d):
        r(_r), c(_c), d(_d){}
    };
    vector<p> l;
    int c = -1;
    int k;
    Robot(int n, int m) {
        for(int i = 1; i<n; i++){
            l.push_back({i, 0, "East"});
        }
        for(int i = 1; i<m; i++){
            l.push_back({n-1, i, "North"});
        }
        for(int i = n-2; i>=0; i--){
            l.push_back({i, m-1, "West"});
        }
        for(int i = m-2; i>=0; i--){
            l.push_back({0, i, "South"});
        }
        k = l.size();
        for(const auto& m : l){
            cout<<m.r<<" "<<m.c<<" "<<m.d<<endl;
        }
    }
    
    bool moved = false;
    void step(int num) {
        moved = true;
        c = (c+num)%k;
    }
    
    vector<int> getPos() {
        if(!moved) return {0, 0};
        return {l[c].r, l[c].c};
    }
    
    string getDir() {
        if(!moved) return "East";
        return l[c].d;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
